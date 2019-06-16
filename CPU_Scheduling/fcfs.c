#include<stdio.h>

main()
{
	int i;
	float P[20],n,W[20],tt=0,wt=0;
	float att,awt;
	printf("Enter the number of processes\n");
	scanf("%f",&n);
	printf("Enter the burst time of the processes\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter the burst time of process %d ",i+1);
		scanf("%f",&P[i]);
	}
	printf("\nProcesses\n\nProcess\tBurst time\tWaiting time");
	
	for(i=0;i<n;i++)
	{
		tt=tt+P[i];
		if(i==0)
			W[i]=0;
		else
		{	
			W[i]=W[i-1]+P[i-1];
			wt=wt+W[i];	
		}	
	}
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t%f\t%f",i,P[i],W[i]);
	}
	att=tt/n;
	awt=wt/n;
	printf("\n\nAverage Turnaround time: %f",att);
	printf("\nAverage Waiting time: %f\n",awt);
}
