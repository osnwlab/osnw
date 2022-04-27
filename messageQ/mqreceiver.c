#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MAX 50
struct msg
{
long msg_type;
char msg_text[MAX];
} message;
void main()
{
key_t key;
int mqid;
key = ftok("ebey.c",55);
mqid = msgget(key,0666);
msgrcv(mqid, &message, sizeof(message), 1, 0);
printf("The message received is %s\n",message.msg_text);
msgctl(mqid,IPC_RMID, NULL);
}
