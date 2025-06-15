/**************************************************************************//**
 * @file     os_systick.c
 * @brief    CMSIS OS Tick SysTick implementation
 * @version  V1.0.1
 * @date     29. November 2017
 ******************************************************************************/
/*
 * Copyright (c) 2017-2017 Arm Limited. All rights reserved.
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
 */

#include "os_tick.h"
static int count = 0;

// Setup OS Tick.
int32_t OS_Tick_Setup (uint32_t freq, IRQHandler_t handler) {
  (void)(freq); //Avoid compiler warnings from unused variable
  (void)(handler);
  return (0);
}

/// Enable OS Tick.
void OS_Tick_Enable (void) {
}

/// Disable OS Tick.
void OS_Tick_Disable (void) {
}

// Acknowledge OS Tick IRQ.
void OS_Tick_AcknowledgeIRQ (void) {
}

// Get OS Tick IRQ number.
int32_t  OS_Tick_GetIRQn (void) {
    return 0;
}

// Get OS Tick clock.
uint32_t OS_Tick_GetClock (void) {
  // return (SystemCoreClock);
	//Return fake value 100MHz. Needs to be changed if you change core clock and make a test that relies on this
  return (100e6);	
}

// Get OS Tick interval.
uint32_t OS_Tick_GetInterval (void) {
	return 100e3;
  // return (SysTick->LOAD + 1U);
}

// Get OS Tick count value.
uint32_t OS_Tick_GetCount (void) {
  // uint32_t load = SysTick->LOAD;
  // return  (load - SysTick->VAL);
	count++;
	return count; // Don't rely on this unless you write a better mock!
}

// Get OS Tick overflow status.
uint32_t OS_Tick_GetOverflow (void) {
  // return ((SysTick->CTRL >> 16) & 1U);
  return 0;
}