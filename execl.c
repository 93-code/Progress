/* 17:30 2015-04-15 Wednesday */
#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    execl("/sbin/reboot","sudo reboot -p %p",NULL);
    return 0;
}


