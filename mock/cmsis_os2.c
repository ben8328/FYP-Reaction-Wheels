/* --------------------------------------------------------------------------
 * Copyright (c) 2013-2017 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *      Name:    cmsis_os2.c
 *      Purpose: CMSIS RTOS2 wrapper for FreeRTOS
 *
 *---------------------------------------------------------------------------*/

#include <string.h>
#include <stdio.h>

// #include "RTE_Components.h"             // Component selection
#define RTE_CMSIS_RTOS2                 /* CMSIS-RTOS2 */
#define RTE_CMSIS_RTOS2_FreeRTOS        /* CMSIS-RTOS2 FreeRTOS */
#define RTE_RTOS_FreeRTOS_CONFIG_RTOS2  /* RTOS FreeRTOS Config for CMSIS RTOS2 API */
#define RTE_RTOS_FreeRTOS_CORE          /* RTOS FreeRTOS Core */
#define RTE_RTOS_FreeRTOS_COROUTINE     /* RTOS FreeRTOS Co-routines */
#define RTE_RTOS_FreeRTOS_EVENTGROUPS   /* RTOS FreeRTOS Event Groups */
#define RTE_RTOS_FreeRTOS_HEAP_4        /* RTOS FreeRTOS Heap 4 */
#define RTE_RTOS_FreeRTOS_MESSAGE_BUFFER /* RTOS FreeRTOS Message Buffers */
#define RTE_RTOS_FreeRTOS_STREAM_BUFFER /* RTOS FreeRTOS Stream Buffers */
#define RTE_RTOS_FreeRTOS_TIMERS        /* RTOS FreeRTOS Timers */

#include "cmsis_os2.h"                  // ::CMSIS:RTOS2
#include "cmsis_compiler.h"
#include "os_tick.h"

#include "FreeRTOS.h"                   // ARM.FreeRTOS::RTOS:Core
// #include "task.h"                       // ARM.FreeRTOS::RTOS:Core
// #include "event_groups.h"               // ARM.FreeRTOS::RTOS:Event Groups
// #include "semphr.h"                     // ARM.FreeRTOS::RTOS:Core

/*---------------------------------------------------------------------------*/
#ifndef __ARM_ARCH_6M__
  #define __ARM_ARCH_6M__         0
#endif
#ifndef __ARM_ARCH_7M__
  #define __ARM_ARCH_7M__         0
#endif
#ifndef __ARM_ARCH_7EM__
  #define __ARM_ARCH_7EM__        0
#endif
#ifndef __ARM_ARCH_8M_MAIN__
  #define __ARM_ARCH_8M_MAIN__    0
#endif
#ifndef __ARM_ARCH_7A__
  #define __ARM_ARCH_7A__         0
#endif

#if   ((__ARM_ARCH_7M__      == 1U) || \
       (__ARM_ARCH_7EM__     == 1U) || \
       (__ARM_ARCH_8M_MAIN__ == 1U))
// #define IS_IRQ_MASKED()           ((__get_PRIMASK() != 0U) || ((KernelState == osKernelRunning) && (__get_BASEPRI() != 0U)))
#elif  (__ARM_ARCH_6M__      == 1U)
// #define IS_IRQ_MASKED()           ((__get_PRIMASK() != 0U) &&  (KernelState == osKernelRunning))
#elif (__ARM_ARCH_7A__       == 1)
#define IS_IRQ_MASKED()           (0U)
#else
#define IS_IRQ_MASKED()           (__get_PRIMASK() != 0U)
#endif

#if    (__ARM_ARCH_7A__      == 1U)
/* CPSR mode bitmasks */
#define CPSR_MODE_USER            0x10U
#define CPSR_MODE_SYSTEM          0x1FU

#define IS_IRQ_MODE()             ((__get_mode() != CPSR_MODE_USER) && (__get_mode() != CPSR_MODE_SYSTEM))
#else
#define IS_IRQ_MODE()             (__get_IPSR() != 0U)
#endif

//TODO: Mock IS_IRQ()
#define IS_IRQ()                  0
/*(IS_IRQ_MODE() || IS_IRQ_MASKED())*/

/* Limits */
#define MAX_BITS_TASK_NOTIFY      31U
#define MAX_BITS_EVENT_GROUPS     24U

#define THREAD_FLAGS_INVALID_BITS (~((1UL << MAX_BITS_TASK_NOTIFY)  - 1U))
#define EVENT_FLAGS_INVALID_BITS  (~((1UL << MAX_BITS_EVENT_GROUPS) - 1U))

/* Kernel version and identification string definition */
#define KERNEL_VERSION           1 //(((uint32_t)tskKERNEL_VERSION_MAJOR * 10000000UL) | \
                                  // ((uint32_t)tskKERNEL_VERSION_MINOR *    10000UL) | \
                                  // ((uint32_t)tskKERNEL_VERSION_BUILD *        1UL))

#define KERNEL_ID                 "FreeRTOS V10.0.1"

//Macro to change the void pointer to the mock_taskHandle_t struct

/* Timer callback information structure definition */
typedef struct {
  osTimerFunc_t func;
  void         *arg;
} TimerCallback_t;

/* Kernel initialization state */
// static osKernelState_t KernelState;

#if defined(SysTick)
/* FreeRTOS tick timer interrupt handler prototype */
extern void xPortSysTickHandler (void);

/*
  SysTick handler implementation that also clears overflow flag.
*/
void SysTick_Handler (void) {
  /* Clear overflow flag */
  SysTick->CTRL;

  /* Call tick handler */
  xPortSysTickHandler();
}
#endif /* SysTick */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#define MAX_TEST_TASKS 20
static mock_taskHandle_t TaskArray[MAX_TEST_TASKS];
static int mock_taskCounter = 0;

#define MAX_TEST_TIMERS 20
static mock_timerHandle_t TimerArray[MAX_TEST_TIMERS];
static int mock_timerCounter = 0;

#define MAX_TEST_EVENTS 20
static mock_eventHandle_t EventArray[MAX_TEST_EVENTS];
static int mock_eventCounter = 0;

osThreadId_t osThreadNew(osThreadFunc_t func, void *argument, const osThreadAttr_t *attr) 
{
    (void) argument;  //Avoid compiler warnings from unused variable
    static mock_taskHandle_t* hTask;
    char empty;
    const char *name;
    osPriority_t prio;
    hTask = NULL;

    if (!IS_IRQ() && (func != NULL)) 
    {
        hTask = &TaskArray[mock_taskCounter];   //Set pointer
        prio  = osPriorityNormal;
        empty = '\0';
        name  = &empty;
        if (attr != NULL) 
        {
            if (attr->name != NULL) 
            {
                name = attr->name;
            }
            if (attr->priority != osPriorityNone) 
            {
                prio = attr->priority;
            }
            if ((prio < osPriorityIdle) || (prio > osPriorityISR))
            {
                return (NULL);
            }
            hTask->pcTaskName = name;
            hTask->uxCurrentPriority = prio;
        }
        hTask->eCurrentState = osThreadRunning;
        hTask->CallbackFunc = *func;
        mock_taskCounter++;                 //Increment number of active threads
    }
    return ((osThreadId_t)hTask);
}

const char *osThreadGetName (osThreadId_t thread_id) {
    mock_taskHandle_t *hTask;
    hTask = mockGetThreadFromHandle(thread_id);
    const char *name;

    if (IS_IRQ() || (hTask == NULL)) 
    {
        name = NULL;
    }
    else 
    {
        name = hTask->pcTaskName;
    }
    return (name);
}

osThreadId_t osThreadGetId (void) {
//  osThreadId_t id;
//
//  if (IS_IRQ()) {
//    id = NULL;
//  } else {
//    id = (osThreadId_t)xTaskGetCurrentTaskHandle();
//  }
//
//  return (id);
  return NULL;
}

osThreadState_t osThreadGetState (osThreadId_t thread_id) 
{
    mock_taskHandle_t *hTask;
    hTask = mockGetThreadFromHandle(thread_id);
    osThreadState_t state;

    if (IS_IRQ() || (hTask == NULL)) 
    {
        state = osThreadError;
    }
    else
    {
        state = hTask->eCurrentState;
    }
//  else {
//    switch (eTaskGetState (hTask)) {
//      case eRunning:   state = osThreadRunning;    break;
//      case eReady:     state = osThreadReady;      break;
//      case eBlocked:
//      case eSuspended: state = osThreadBlocked;    break;
//      case eDeleted:   state = osThreadTerminated; break;
//      case eInvalid:
//      default:         state = osThreadError;      break;
//    }
//  }
//
    return (state);
}

uint32_t osThreadGetStackSpace (osThreadId_t thread_id) {
     (void) thread_id; //Avoid compiler warnings from unused variable
//  TaskHandle_t hTask = (TaskHandle_t)thread_id;
//  uint32_t sz;
//
//  if (IS_IRQ() || (hTask == NULL)) {
//    sz = 0U;
//  } else {
//    sz = (uint32_t)uxTaskGetStackHighWaterMark (hTask);
//  }
//
//  return (sz);
  return 0;
}

osStatus_t osThreadSetPriority (osThreadId_t thread_id, osPriority_t priority) {
    mock_taskHandle_t *hTask;
    hTask = mockGetThreadFromHandle(thread_id);

    osStatus_t stat;
    if (IS_IRQ()) {
      stat = osErrorISR;
    }
    else if ((hTask == NULL) || (priority < osPriorityIdle) || (priority > osPriorityISR)) {
      stat = osErrorParameter;
    }
    else {
      stat = osOK;
      hTask->uxCurrentPriority = priority;
    }
    return (stat);
}

osPriority_t osThreadGetPriority (osThreadId_t thread_id) {
    mock_taskHandle_t *hTask;
    hTask = mockGetThreadFromHandle(thread_id);
    osPriority_t prio;

    if (IS_IRQ() || (hTask == NULL)) {
    prio = osPriorityError;
    } else {
    prio = (osPriority_t)hTask->uxCurrentPriority;
    }

    return (prio);
}

osStatus_t osThreadYield (void) {
//  osStatus_t stat;
//
//  if (IS_IRQ()) {
//    stat = osErrorISR;
//  } else {
//    stat = osOK;
//    taskYIELD();
//  }
//
//  return (stat);
    return osOK;
}

osStatus_t osThreadSuspend (osThreadId_t thread_id) {
    mock_taskHandle_t *hTask;
    hTask = mockGetThreadFromHandle(thread_id);
    osStatus_t stat;
    if (IS_IRQ()) {
        stat = osErrorISR;
    }
    else if (hTask == NULL) {
        stat = osErrorParameter;
    }
    else if (hTask->CallbackFunc == NULL){
        stat = osErrorParameter;
    }
    else {
        stat = osOK;
        hTask->eCurrentState = osThreadInactive;
    }
    return (stat);
}

osStatus_t osThreadResume (osThreadId_t thread_id) {
    mock_taskHandle_t *hTask;
    hTask = mockGetThreadFromHandle(thread_id);
    osStatus_t stat;

    if (IS_IRQ()) {
        stat = osErrorISR;
    }
    else if (hTask == NULL) {
        stat = osErrorParameter;
    }
    else if (hTask->CallbackFunc == NULL){
        stat = osErrorParameter;
    }
    else {
        stat = osOK;
        hTask->eCurrentState = osThreadRunning;
    }

    return (stat);
}

void osThreadExit (void) {
//#ifndef RTE_RTOS_FreeRTOS_HEAP_1
//  vTaskDelete (NULL);
//#endif
  // for (;;);
}

osStatus_t osThreadTerminate (osThreadId_t thread_id) {
    (void) thread_id;
//  TaskHandle_t hTask = (TaskHandle_t)thread_id;
//  osStatus_t stat;
//#ifndef RTE_RTOS_FreeRTOS_HEAP_1
//  eTaskState tstate;
//
//  if (IS_IRQ()) {
//    stat = osErrorISR;
//  }
//  else if (hTask == NULL) {
//    stat = osErrorParameter;
//  }
//  else {
//    tstate = eTaskGetState (hTask);
//
//    if (tstate != eDeleted) {
//      stat = osOK;
//      vTaskDelete (hTask);
//    } else {
//      stat = osErrorResource;
//    }
//  }
//#else
//  stat = osError;
//#endif
//
//  return (stat);

  return osOK;
}

void mockThreadTeardownAll(void)
{
    for(int i = 0; i<mock_taskCounter; i++)
    {
        TaskArray[i].pcTaskName =           NULL;
        TaskArray[i].uxCurrentPriority =    0;
        TaskArray[i].eCurrentState =        0;
        TaskArray[i].CallbackFunc =         NULL;
    }
    mock_taskCounter = 0;
}


osStatus_t osDelay (uint32_t ticks) {
    (void) ticks;  //Avoid compiler warnings from unused variable
//  osStatus_t stat;
//
//  if (IS_IRQ()) {
//    stat = osErrorISR;
//  }
//  else {
//    stat = osOK;
//
//    if (ticks != 0U) {
//      vTaskDelay(ticks);
//    }
//  }
//
//  return (stat);
    return osOK;
}

osStatus_t osDelayUntil (uint32_t ticks) {
    (void) ticks;  //Avoid compiler warnings from unused variable
//  TickType_t tcnt;
//  osStatus_t stat;
//
//  if (IS_IRQ()) {
//    stat = osErrorISR;
//  }
//  else {
//    stat = osOK;
//    tcnt = xTaskGetTickCount();
//
//    vTaskDelayUntil (&tcnt, (TickType_t)ticks);
//  }
//
//  return (stat);
    return osOK;
}

/*---------------------------------------------------------------------------*/

// Commented out as unused without actual ISRs
// static void TimerCallback (TimerHandle_t hTimer) {
//     (void)hTimer;  //Avoid compiler warnings from unused variable
// //  TimerCallback_t *callb;
// //
// //  callb = (TimerCallback_t *)pvTimerGetTimerID (hTimer);
// //
// //  if (callb != NULL) {
// //    callb->func (callb->arg);
// //  }
// }

osTimerId_t osTimerNew (osTimerFunc_t func, osTimerType_t type, void *argument, const osTimerAttr_t *attr) {
    (void) argument;  //Avoid compiler warnings from unused variable
    static mock_timerHandle_t* hTimer;
    char empty;
    const char *name;
    hTimer = NULL;
    if (!IS_IRQ() && (func != NULL)) {
        hTimer = &TimerArray[mock_timerCounter];   //Set pointer
        empty = '\0';
        name  = &empty;
        if (attr != NULL) {
           if (attr->name != NULL) {
               name = attr->name;
           }
        }
        hTimer->pcTimerName = name;
        hTimer->uxAutoReload = type;
        hTimer->pxCallbackFunction = func;
        hTimer->xTimerState = osTimerReady;
        hTimer->xTimerPeriodInTicks = -1; //-1 is sentinel value to show osTimerStart() hasn't been called TODO: use enum or #define
        mock_timerCounter++;
    }
    return ((osTimerId_t)hTimer);
}

const char *osTimerGetName (osTimerId_t timer_id) {
    timer_id = spyCheckInitialisedTimerId(timer_id);
    mock_timerHandle_t *hTimer;
    hTimer = mockGetTimerFromHandle(timer_id);
    const char *name;

     if (IS_IRQ() || (hTimer == NULL)) {
       name = NULL;
     } else {
       name = hTimer->pcTimerName;
     }

 return name;
}

osStatus_t osTimerStart (osTimerId_t timer_id, uint32_t ticks) {
    timer_id = spyCheckInitialisedTimerId(timer_id);
    mock_timerHandle_t *hTimer;
    hTimer = mockGetTimerFromHandle(timer_id);    osStatus_t stat;

    if (IS_IRQ()) {
        stat = osErrorISR;
    }
    else if (hTimer == NULL) {
        stat = osErrorParameter;
    }
    else {
        hTimer->xTimerState = osTimerRunning;
        hTimer->xTimerPeriodInTicks = ticks;
        stat = osOK;
    }

 return (stat);
}

osStatus_t osTimerStop (osTimerId_t timer_id) {
    timer_id = spyCheckInitialisedTimerId(timer_id);
    mock_timerHandle_t *hTimer;
    hTimer = mockGetTimerFromHandle(timer_id);
    osStatus_t stat;

    if (IS_IRQ()) {
        stat = osErrorISR;
    }
    else if (hTimer == NULL) {
        stat = osErrorParameter;
    }
    else {
        hTimer->xTimerState = osTimerStopped;
        stat = osOK;
    }
    return (stat);
}

uint32_t osTimerIsRunning (osTimerId_t timer_id) {
    timer_id = spyCheckInitialisedTimerId(timer_id);
    mock_timerHandle_t *hTimer;
    hTimer = mockGetTimerFromHandle(timer_id);
    uint32_t running;
    if (IS_IRQ() || (hTimer == NULL)) {
        running = osTimerError;
    } else {
        running = hTimer->xTimerState;
    }
    return (running);
}

osStatus_t osTimerDelete (osTimerId_t timer_id) {
    (void) timer_id;  //Avoid compiler warnings from unused variable
//  TimerHandle_t hTimer = (TimerHandle_t)timer_id;
//  osStatus_t stat;
//#ifndef RTE_RTOS_FreeRTOS_HEAP_1
//  TimerCallback_t *callb;
//
//  if (IS_IRQ()) {
//    stat = osErrorISR;
//  }
//  else if (hTimer == NULL) {
//    stat = osErrorParameter;
//  }
//  else {
//    callb = (TimerCallback_t *)pvTimerGetTimerID (hTimer);
//
//    if (xTimerDelete (hTimer, 0) == pdPASS) {
//      vPortFree (callb);
//      stat = osOK;
//    } else {
//      stat = osErrorResource;
//    }
//  }
//#else
//  stat = osError;
//#endif
//
//  return (stat);
    return osOK;
}

void mockTimerTeardownAll(void)
{
    for(int i = 0; i<mock_timerCounter; i++)
    {
        TimerArray[i].pcTimerName           =   NULL;
        TimerArray[i].xTimerPeriodInTicks   =   -1;
        TimerArray[i].uxAutoReload          =   0;
        TimerArray[i].pxCallbackFunction    =   NULL;
        TimerArray[i].xTimerState           =   osTimerInactive;
    }
    mock_timerCounter = 0;
}

/*---------------------------------------------------------------------------*/

osEventFlagsId_t osEventFlagsNew (const osEventFlagsAttr_t *attr) {
    static mock_eventHandle_t* hEventGroup;
    char empty;
    const char *name;
    hEventGroup = NULL;
    if (!IS_IRQ()) {
        hEventGroup = &EventArray[mock_eventCounter];   //Set pointer
        empty = '\0';
        name  = &empty;    
        if (attr != NULL) {
           if (attr->name != NULL) {
               name = attr->name;
           }
        }
        hEventGroup->pcEventName = name;
        hEventGroup->xEventFlags = 0x0000;
        mock_eventCounter++;
    }
    return ((osEventFlagsId_t)hEventGroup);
}

uint32_t osEventFlagsSet (osEventFlagsId_t ef_id, uint32_t flags) {
    ef_id = spyCheckInitialisedEventId(ef_id);
    mock_eventHandle_t *hEvent;
    hEvent = mockGetEventFromHandle(ef_id);
    uint32_t rflags;

    if ((hEvent == NULL) || ((flags & EVENT_FLAGS_INVALID_BITS) != 0U)) {
        rflags = (uint32_t)osErrorParameter;
    }
    else {
        hEvent->xEventFlags |= flags;
        rflags = hEvent->xEventFlags; 
    }
    return (rflags);
}

uint32_t osEventFlagsClear (osEventFlagsId_t ef_id, uint32_t flags) {
    ef_id = spyCheckInitialisedEventId(ef_id);
    mock_eventHandle_t *hEvent;
    hEvent = mockGetEventFromHandle(ef_id);
    uint32_t rflags;

    if ((hEvent == NULL) || ((flags & EVENT_FLAGS_INVALID_BITS) != 0U)) {
        rflags = (uint32_t)osErrorParameter;
    }
    else {
        hEvent->xEventFlags &= ~flags;
        rflags = hEvent->xEventFlags;
    }
    return (rflags);
}

uint32_t osEventFlagsGet (osEventFlagsId_t ef_id) {

    ef_id = spyCheckInitialisedEventId(ef_id);
    mock_eventHandle_t *hEvent;
    hEvent = mockGetEventFromHandle(ef_id);
    uint32_t rflags;

    if (hEvent == NULL) {
        rflags = (uint32_t)osErrorParameter;
    }
    else {
        rflags = hEvent->xEventFlags;
    }
    return (rflags);
}

uint32_t osEventFlagsWait (osEventFlagsId_t ef_id, uint32_t flags, uint32_t options, uint32_t timeout) {
    ef_id = spyCheckInitialisedEventId(ef_id);
    mock_eventHandle_t *hEvent;
    hEvent = mockGetEventFromHandle(ef_id);
    // int wait_all; //Todo: write mock.
    // int exit_clr; //Todo: write mock.
    uint32_t rflags;
    
    if ((hEvent == NULL) || ((flags & EVENT_FLAGS_INVALID_BITS) != 0U)) {
    rflags = (uint32_t)osErrorParameter;
    }
    else if (IS_IRQ()) {
    rflags = (uint32_t)osErrorISR;
    }
    else {
        if (options & osFlagsWaitAll) {
            // wait_all = 1;
        }   else {
            // wait_all = 0;
        }
        
        if (options & osFlagsNoClear) {
          // exit_clr = 0;
          //ALEX: Might not implement this yet. TODO! If you need this -- write the rest of this mock! ;)
        } else {
          // exit_clr = 1;
        }

        rflags = hEvent->xEventFlags;

        if (options & osFlagsWaitAll) {
            if (flags != rflags) {
                if (timeout > 0U) {
                    rflags = (uint32_t)osErrorTimeout;
                }   else {
                    rflags = (uint32_t)osErrorResource;
                }
            }
        }
        else {
            if ((flags & rflags) == 0U) {
                if (timeout > 0U) {
                    rflags = (uint32_t)osErrorTimeout;
                }   else {
                    rflags = (uint32_t)osErrorResource;
                }
            }
        }
    }
    return (rflags);
}

osStatus_t osEventFlagsDelete (osEventFlagsId_t ef_id) {
    (void) ef_id;  //Avoid compiler warnings from unused variable
//  EventGroupHandle_t hEventGroup = (EventGroupHandle_t)ef_id;
//  osStatus_t stat;
//
//#ifndef RTE_RTOS_FreeRTOS_HEAP_1
//  if (IS_IRQ()) {
//    stat = osErrorISR;
//  }
//  else if (hEventGroup == NULL) {
//    stat = osErrorParameter;
//  }
//  else {
//    stat = osOK;
//    vEventGroupDelete (hEventGroup);
//  }
//#else
//  stat = osError;
//#endif
//
//  return (stat);
    return osOK;
}

void mockEventTeardownAll(void)
{
    for(int i = 0; i<mock_eventCounter; i++)
    {
        EventArray[i].pcEventName           =   NULL;
        // EventArray[i].xEventPeriodInTicks   =   -1;
        // EventArray[i].uxAutoReload          =   0;
        // EventArray[i].pxCallbackFunction    =   NULL;
        // EventArray[i].xEventState           =   osEventInactive;
    }
    mock_eventCounter = 0;
}

/*---------------------------------------------------------------------------*/

// /* Callback function prototypes */
// extern void vApplicationIdleHook (void);
// extern void vApplicationTickHook (void);
// extern void vApplicationMallocFailedHook (void);
// extern void vApplicationDaemonTaskStartupHook (void);
// extern void vApplicationStackOverflowHook (TaskHandle_t xTask, signed char *pcTaskName);
// 
// /**
//   Dummy implementation of the callback function vApplicationIdleHook().
// */
// #if (configUSE_IDLE_HOOK == 1)
// __WEAK void vApplicationIdleHook (void){}
// #endif
// 
// /**
//   Dummy implementation of the callback function vApplicationTickHook().
// */
// #if (configUSE_TICK_HOOK == 1)
//  __WEAK void vApplicationTickHook (void){}
// #endif
// 
// /**
//   Dummy implementation of the callback function vApplicationMallocFailedHook().
// */
// #if (configUSE_MALLOC_FAILED_HOOK == 1)
// __WEAK void vApplicationMallocFailedHook (void){}
// #endif
// 
// /**
//   Dummy implementation of the callback function vApplicationDaemonTaskStartupHook().
// */
// #if (configUSE_DAEMON_TASK_STARTUP_HOOK == 1)
// __WEAK void vApplicationDaemonTaskStartupHook (void){}
// #endif
// 
// /**
//   Dummy implementation of the callback function vApplicationStackOverflowHook().
// */
// #if (configCHECK_FOR_STACK_OVERFLOW > 0)
// __WEAK void vApplicationStackOverflowHook (TaskHandle_t xTask, signed char *pcTaskName) {
//   (void)xTask;
//   (void)pcTaskName;
// }
// #endif
// 
// /*---------------------------------------------------------------------------*/
// 
// /* External Idle and Timer task static memory allocation functions */
// extern void vApplicationGetIdleTaskMemory  (StaticTask_t **ppxIdleTaskTCBBuffer,  StackType_t **ppxIdleTaskStackBuffer,  uint32_t *pulIdleTaskStackSize);
// extern void vApplicationGetTimerTaskMemory (StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize);
// 
// /* Idle task control block and stack */
// static StaticTask_t Idle_TCB;
// static StackType_t  Idle_Stack[configMINIMAL_STACK_SIZE];
// 
// /* Timer task control block and stack */
// static StaticTask_t Timer_TCB;
// static StackType_t  Timer_Stack[configTIMER_TASK_STACK_DEPTH];
// 
// /*
//   vApplicationGetIdleTaskMemory gets called when configSUPPORT_STATIC_ALLOCATION
//   equals to 1 and is required for static memory allocation support.
// */
// void vApplicationGetIdleTaskMemory (StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize) {
//   *ppxIdleTaskTCBBuffer   = &Idle_TCB;
//   *ppxIdleTaskStackBuffer = &Idle_Stack[0];
//   *pulIdleTaskStackSize   = (uint32_t)configMINIMAL_STACK_SIZE;
// }
// 
// /*
//   vApplicationGetTimerTaskMemory gets called when configSUPPORT_STATIC_ALLOCATION
//   equals to 1 and is required for static memory allocation support.
// */
// void vApplicationGetTimerTaskMemory (StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize) {
//   *ppxTimerTaskTCBBuffer   = &Timer_TCB;
//   *ppxTimerTaskStackBuffer = &Timer_Stack[0];
//   *pulTimerTaskStackSize   = (uint32_t)configTIMER_TASK_STACK_DEPTH;
// }
// 

uint32_t osKernelGetTickCount (void) {
  return 0;
}

uint32_t osKernelGetTickFreq (void) {
  return 1000;
}

uint32_t osKernelGetSysTimerCount (void) {
  return 0;
}

uint32_t osKernelGetSysTimerFreq (void) {
  return 100e6;
}


osThreadId_t spyGetThreadId(const char* target_name)
{
    for(int i = 0; i<mock_taskCounter; i++)
    {
        if(!strcmp(TaskArray[i].pcTaskName, target_name))
        {
            return &TaskArray[i];
        }
    }
    //If here, never found the right task so return NULL pointer
    return NULL;
}

osThreadId_t spyCheckInitialisedThreadId(osThreadId_t task_id)
{
    mock_taskHandle_t *hTask;
    hTask = mockGetThreadFromHandle(task_id);
    for(int i = 0; i<mock_taskCounter; i++)
    {
        if(&TaskArray[i] == hTask)
        {
            return task_id;
        }
    }
    //If here, the thread ID was never initialised so return NULL pointer
    return NULL;
}

osTimerId_t spyGetTimerId(const char* target_name)
{
    for(int i = 0; i<mock_timerCounter; i++)
    {
        if(!strcmp(TimerArray[i].pcTimerName, target_name))
        {
            return &TimerArray[i];
        }
    }
    //If here, never found the right timer so return NULL pointer
    return NULL;
}

osTimerId_t spyCheckInitialisedTimerId(osTimerId_t timer_id)
{
    mock_timerHandle_t *hTimer;
    hTimer = mockGetTimerFromHandle(timer_id);
    for(int i = 0; i<mock_timerCounter; i++)
    {
        if(&TimerArray[i] == hTimer)
        {
            return timer_id;
        }
    }
    //If here, the timer ID was never initialised so return NULL pointer
    return NULL;
}

osEventFlagsId_t spyGetEventId(const char* target_name)
{
    for(int i = 0; i<mock_eventCounter; i++)
    {
        if(!strcmp(EventArray[i].pcEventName, target_name))
        {
            return &EventArray[i];
        }
    }
    //If here, never found the right timer so return NULL pointer
    return NULL;
}

osEventFlagsId_t spyCheckInitialisedEventId(osEventFlagsId_t event_id)
{
    mock_eventHandle_t *hEvent;
    hEvent = mockGetEventFromHandle(event_id);
    for(int i = 0; i<mock_eventCounter; i++)
    {
        if(&EventArray[i] == hEvent)
        {
            return event_id;
        }
    }
    //If here, the event ID was never initialised so return NULL pointer
    return NULL;
}
