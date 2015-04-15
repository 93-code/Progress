/* 14:37 2015-04-15 Wednesday */
#include <stdio.h>
#include <string.h>
#include <errno.h>


int main(int argc, const char *argv[])
{
    int pid1,pid2;

    pid1 = fork();
    
    if (pid1 < 0)
    {
        perror("Fail to fork!\n");
        return -1;
    }

    if (pid1 > 0)
    {
        
        pid2 = fork();
    if (pid2 < 0)
    {
        perror("Fail to fork!\n");
        return -1;
    }
        while (1);
    }
    else
    {
        sleep(3);
        return -1;
    }
    return 0;
}

