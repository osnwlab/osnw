#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
void main()
{
void *shared_memory;
key_t key;
int shmid;
key = ftok("SHM",65);
shmid = shmget(key, 1024, 0666);
shared_memory = shmat(shmid, NULL, 0);
printf("The message received is %s\n",(char*)shared_memory);
shmdt(shared_memory);
shmctl(shmid, IPC_RMID, NULL); 
}
