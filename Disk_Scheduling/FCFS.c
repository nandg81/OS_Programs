//Program to implement FCFS disk scheduling
//Author: Nandagopal

#include<stdio.h>

main()
{
	int i,n,q[50],h,diff,seek=0,aseek;
	printf("\nEnter the number of IO requests ");
	scanf("%d",&n);
	printf("\nEnter the initial head position ");
	scanf("%d",&h);
	printf("\nEnter the head positions required for IO requests\n");
	for(i=1;i<=n;i++)
	{
		printf("\nEnter the head position required for IO request %d ",i);
		scanf("%d",&q[i]);
	}
	q[0]=h;
	printf("\n");
	for(i=0;i<n;i++)
	{
		if(q[i+1]>q[i])
			diff=q[i+1]-q[i];
		else
			diff=q[i]-q[i+1];
		seek=seek+diff;
		printf("\nHead moved from %d to %d with a seek of %d",q[i],q[i+1],diff);
	}
	printf("\nTotal seek time = %d",seek);
	aseek=seek/n;
	printf("\nAverage seek time = %d\n",aseek);
}

