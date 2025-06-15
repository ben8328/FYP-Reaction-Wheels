#include <stdio.h>
#include <string.h>
#include "heartbeat_task.h"
#include "heartbeat_cmd.h"

void heartbeat_cmd(int argc, char *argv[])
{
    if (argc <= 1)
    {
        if (heartbeat_task_is_running())
            printf("Heartbeat is currently running\n");
        else
            printf("Heartbeat is not currently running\n");
    }
    else
    {
        if (strcmp(argv[1], "start") == 0)
        {
            heartbeat_task_start();
            printf("Heartbeat has started\n");
        }
        else if (strcmp(argv[1], "stop") == 0)
        {
            heartbeat_task_stop();
            printf("Heartbeat has stopped\n");
        }
        else
        {
            printf("%s: invalid argument \"%s\", syntax is: %s [start|stop]\n", argv[0], argv[1], argv[0]);
        }
    }
}