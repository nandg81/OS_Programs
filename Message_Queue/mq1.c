//Client program to pass strings through message queue
//Author: Nandagopal

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<ctype.h>

typedef struct 
{
	long type;
	char msg[100];
}msgbuff;

main()
{
	int msgid,x,y,z;
	msgbuff m1,m2,m3;

	msgid=msgget(193,IPC_CREAT|0666);
	printf("\nEnter the first string to be passed ");
	gets(m1.msg);
	//scanf("%s",m1.msg);
	printf("\nEnter the second string to be passed ");
	gets(m2.msg);
	//scanf("%s",m2.msg);
	m1.type=1;
	m2.type=1;
	msgsnd(msgid,&m1,sizeof(m1),0);
	msgsnd(msgid,&m2,sizeof(m2),0);
	sleep(10);
	msgrcv(msgid,&m3,sizeof(m3),3,0);
	printf("Concatenated string:");
	puts(m3.msg);
}
