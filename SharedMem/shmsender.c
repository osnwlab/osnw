#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
void main()
{
void *shared_memory;
key_t key;
int shmid;
key = ftok("SHM",65);
shmid = shmget(key, 1024, 0666|IPC_CREAT);
shared_memory = shmat(shmid, NULL, 0);
printf("Enter the message to be send\n");
fgets(shared_memory, 100, stdin);
printf("The message sent is %s\n",(char*)shared_memory);
shmdt(shared_memory);
}
