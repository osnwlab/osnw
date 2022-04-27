#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
int res;
char msg[]="Good Day dear friend\n";
res=open("FIFO", O_WRONLY);
write(res,msg, sizeof(msg));
printf("Sender process with pid %d sends the message\n",getpid());
}
