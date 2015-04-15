/* 15:29 2015-04-15 Wednesday */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int read_fork(int fd)
{
    int n;
    char buf[48];
    while (1)
    {
        n = read(fd,buf,sizeof(buf)-1);
        buf[n] = '\0';
        if (n == 0)
            continue;

        printf("Read %d bytes : %s\n",n,buf);

        if (strncmp(buf,"quit",4) == 0)
        {
            break;
        }
    }
    return 0;
}

int write_fork(int fd)
{
    char buf[48];
    while (1)
    {
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)-1] = '\0';
        
       if ( write(fd,buf,strlen(buf)) < 0 )
       {
           perror("Fail to write");
           break;
       }
        if (strncmp(buf,"quit",4) == 0)
        {
            break;
        }
    }
    return 0;
}

int main(int argc, const char *argv[])
{
    int fd;
    pid_t pid;

    if (argc < 2)
    {
        fprintf(stderr,"Usage : %s filename\n",argv[0]);
        return -1;
    } 
    fd = open(argv[1],O_WRONLY| O_CREAT | O_TRUNC,0666);
    if (fd < 0)
    {
        fprintf(stderr,"Fail to open %s",argv[1]);
        return -1;
    }
    pid = fork();
    if (pid < 0)
    {
        perror("Fail to fork");
        return -1;
    }

    if ( pid == 0)
    {
        close(fd);

        fd = open(argv[1],O_RDONLY);
        if (fd < 0)
        {
            perror("error");
            return -1;
        }
        read_fork(fd);

    }else{
    write_fork(fd);
    }

    return 0;
}
