#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>

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
key = ftok("hello.c",55);
mqid = msgget(key, 0666|IPC_CREAT);
message.msg_type = 1;
printf("Enter the message\t");
fgets(message.msg_text, MAX, stdin);
msgsnd(mqid, &message, sizeof(message), 0);
printf("The message send is %s\n",message.msg_text);
}
