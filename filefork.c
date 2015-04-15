/* 15:29 2015-04-15 Wednesday */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int fun(int fd)
{
    int n;
    int pid;
    char buf[48];

    pid = fork();
    if (pid < 0)
    {
        perror("Fail to fork");
        return -1;
    }
    while (1)
    {
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)-1] = '\0';
        write(fd,buf,strlen(buf));
        if (strncmp(buf,"quit",4) == 0)
        {
            break;
        }
    }

        lseek(fd,0,SEEK_SET);
        while ((n = read(fd,buf,sizeof(buf))) != 0)
        {
            buf[n] = '\0';

            printf("Read %d bytes : %s\n",n,buf);

            if (strncmp(buf,"quit",4) == 0)
            {
                return;
            }
        }

    printf("=======\n");
    return 0;
}
int main(int argc, const char *argv[])
{
    int fd;

    if (argc < 2)
    {
        fprintf(stderr,"Usage : %s filename\n",argv[0]);
        return -1;
    } 
    fd = open(argv[1],O_RDWR| O_CREAT | O_TRUNC,0666);
    if (fd == 0)
    {
        fprintf(stderr,"Fail to open %s",argv[1]);
        return -1;
    }
    fun(fd);
    close(fd);
    return 0;
}
