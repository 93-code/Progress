#include <stdio.h>

int main(int argc, const char *argv[])
{
    int pid;

    while (1)
    {
        pid = fork();
        if (pid < 0)
        {
            perror("Fail to fork!\n");
            return -1;
        }

        if (pid == 0)
        {
            while (1);
        }
    }
    return 0;
}
