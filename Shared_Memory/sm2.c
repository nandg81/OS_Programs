//Server program to read and evaluate expression from shared memory
//Author: Nandagopal

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

main()
{
	int shmid,l,i,result=0;
	char str[20];
	void *addr=NULL;
	shmid=shmget(97,100,IPC_CREAT|0666);//create shared memory
	addr=shmat(shmid,NULL,0);//attach shared memory to program address space
	sscanf(addr,"%s",str);//read from shared memory
	l=strlen(str);
	for(i=0;i<l;i++)//For evaluating the expression
	{
		if(isdigit(str[i]))
			result=result+str[i]-48;//if it is a digit,add it and for ASCII adjustment, subtract 48
	}
	printf("\nServer\n\nResult = %d\n",result);
	shmdt(addr);
}
