#include<stdio.h>

main()
{
	int t,i,j,min,flag=0;
	int finished[20];
	float P[20],n,W[20],A[20],PR[20],tt=0,wt=0;
	float att,awt;
	printf("Enter the number of processes\n");
	scanf("%f",&n);
	printf("Enter the burst time of the processes\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter the burst time of process %d ",i+1);
		scanf("%f",&P[i]);
		finished[i]=0;	
	}
	printf("Enter the arrival time of the processes\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter the arrival time of process %d ",i+1);
		scanf("%f",&A[i]);
	}
	printf("Enter the priority of the processes\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter the priority of process %d ",i+1);
		scanf("%f",&PR[i]);
	}
	t=0;
	while(1)
	{
		for(i=0;i<n;i++)
		{
			if(!finished[i])
			{
				min=i;
				if(t>=A[i])
				{
					flag=0;
					for(j=i+1;j<n;j++)
					{
						if((PR[i]>PR[j])&&(!finished[j])&&(t>=A[j]))
						{
							flag=1;
							break;
						}
					}
					if(flag==0)
					{
						W[i]=t-A[i];
						t=t+P[i];
						finished[i]=1;
					}
				}
			}
		}
		flag=0;
		for(i=0;i<n;i++)
		{
			if(!finished[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			break;
	}
	for(i=0;i<n;i++)
	{
		wt=wt+W[i];
		tt=tt+P[i];
	}
	printf("\nProcesses\n\nProcess\tBurst time\tArrival time\tPriority\tWaiting time");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t%f\t%f\t%f\t%f",i,P[i],A[i],PR[i],W[i]);
	}
	att=tt/n;
	awt=wt/n;
	printf("\n\nAverage Turnaround time: %f",att);
	printf("\nAverage Waiting time: %f\n",awt);
}
