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
	msgid=msgget(193,IPC_CREAT|0666);//Creating message queue with unique key
	printf("\nEnter the first string to be passed ");
	gets(m1.msg);
	printf("\nEnter the second string to be passed ");
	gets(m2.msg);
	m1.type=1;//setting message types
	m2.type=1;
	msgsnd(msgid,&m1,sizeof(m1),0);//sending first message
	msgsnd(msgid,&m2,sizeof(m2),0);//sending second message
	sleep(10);//waiting for server to send back the concatenated message
	msgrcv(msgid,&m3,sizeof(m3),3,0);//receiving from server
	printf("Concatenated string: ");
	puts(m3.msg);
	exit(0);
}

