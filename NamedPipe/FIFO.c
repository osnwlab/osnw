#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
void main()
{
int res;
res=mkfifo("FIFO",0777);
printf("Named Pipe FIFO is created\n");
}
