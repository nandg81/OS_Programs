//Client program to write expression into shared memory
//Author: Nandagopal

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

main()
{
	int shmid;
	void *addr=NULL;
	shmid=shmget(97,100,IPC_CREAT|0666);//create shared memory
	addr=shmat(shmid,NULL,0);//attach shared memory to program address space
	sprintf(addr,"4+3+2");//write to shared memory
	printf("\nClient\n\nExpression written to shared memory\n");
	shmdt(addr);
}
