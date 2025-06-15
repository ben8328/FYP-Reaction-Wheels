#ifndef HEARTBEAT_TASK_H
#define HEARTBEAT_TASK_H

#include <stdint.h>

void    heartbeat_task_init(void);
void    heartbeat_task_deinit(void);
void    heartbeat_task_start(void);
void    heartbeat_task_stop(void);
uint8_t heartbeat_task_is_running(void);

#endif
