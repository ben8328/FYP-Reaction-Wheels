#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "controller.h"
#include "controller_cmd.h"

void controller_cmd(int argc, char *argv[])
{
    const char *usage = "%s: syntax:\n"
                        "  %s init\n"
                        "  %s get u1|u2|u3\n"
                        "  %s set x1|x2|x3|x4|x5|x6|x7|x8 <value>\n";

    if (argc == 2)
    {
        if (strcmp(argv[1], "init") == 0)
        {
            ctrl_init();
            printf("Controller has initialised\n");
        }
        else
        {
            printf(usage, argv[0], argv[0], argv[0], argv[0]);
        }
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], "get") == 0)
        {
            float* u = ctrl_run(); // compute -K*x
            if (strcmp(argv[2], "u1") == 0)
            {
                printf("%g\n", u[0]);
            }
            else if (strcmp(argv[2], "u2") == 0)
            {
                printf("%g\n", u[1]);
            }
            else if (strcmp(argv[2], "u3") == 0)
            {
                printf("%g\n", u[2]);
            }
            else
            {
                printf("%s: invalid argument \"%s\", syntax is: %s [init]|[get u1|u2|u3]|[set x1|x2|x3|x4|x5|x6|x7|x8 <value>]\n", argv[0], argv[2], argv[0]);
            }
        }
        else
        {
            printf(usage, argv[0], argv[0], argv[0], argv[0]);
        }
    }
    else if (argc == 4)
    {
        if (strcmp(argv[1], "set") == 0)
        {
            float val = atof(argv[3]);

            if (strcmp(argv[2], "x1") == 0) { ctrl_set_x1(val); }
            else if (strcmp(argv[2], "x2") == 0) { ctrl_set_x2(val); }
            else if (strcmp(argv[2], "x3") == 0) { ctrl_set_x3(val); }
            else if (strcmp(argv[2], "x4") == 0) { ctrl_set_x4(val); }
            else if (strcmp(argv[2], "x5") == 0) { ctrl_set_x5(val); }
            else if (strcmp(argv[2], "x6") == 0) { ctrl_set_x6(val); }
            else if (strcmp(argv[2], "x7") == 0) { ctrl_set_x7(val); }
            else if (strcmp(argv[2], "x8") == 0) { ctrl_set_x8(val); }
            else
            {
                printf(usage, argv[0], argv[0], argv[0], argv[0]);
            }
        }
        else
        {
            printf(usage, argv[0], argv[0], argv[0], argv[0]);
        }
    }
    else
    {
        printf("%s: unexpected arguments, %d received\n", argv[0], argc - 1);
        printf(usage, argv[0], argv[0], argv[0], argv[0]);
    }
}
