//Server program to concatenate strings through message queue
//Author: Nandagopal

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>

typedef struct 
{
	long type;
	char msg[100];
}msgbuff;

main()
{
	int msgid,w,y,z;
	char x[20];
	msgbuff m1,m2,m3;
	msgid=msgget(193,IPC_CREAT|0666);//creating message queue with unique key
	msgrcv(msgid,&m1,sizeof(m1),1,0);//receiving first message from client
	printf("First string:");
	puts(m1.msg);
	msgrcv(msgid,&m2,sizeof(m2),1,0);//receiving second message from client
	printf("\nSecond string:");
	puts(m2.msg);
	strcpy(x,m1.msg);
	strcat(x,m2.msg);
	strcpy(m3.msg,x);//concatenating the strings
	printf("\nConcatenated string: ");
	puts(m3.msg);
	m3.type=3;
	msgsnd(msgid,&m3,sizeof(m3),0);//sending the concatenated string to the client
}

