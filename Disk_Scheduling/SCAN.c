//Program to implement SCAN disk scheduling
//Author: Nandagopal

#include<stdio.h>
void asort(int A[50],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			if(A[j]>A[j+1])
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
}
void dsort(int A[50],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			if(A[j]<A[j+1])
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
}
main()
{
	int i,n,q[50],tq1[30],tq2[30],tq[50],h,ph,max,diff,flag,seek=0,aseek,count1=1,count2=1;
	printf("\nEnter the number of IO requests ");
	scanf("%d",&n);
	printf("\nEnter the initial head position ");
	scanf("%d",&h);
	printf("\nEnter the previous head position ");
	scanf("%d",&ph);
	printf("\nEnter the maximum head position ");
	scanf("%d",&max);
	if(ph>h)
		flag=0;
	else
		flag=1;
	printf("\nEnter the head positions required for IO requests\n");
	for(i=1;i<=n;i++)
	{
		printf("\nEnter the head position required for IO request %d ",i);
		scanf("%d",&q[i]);
	}
	if(flag==1)
	{
		for(i=1;i<=n;i++)
		{
			if(q[i]>h)
			{
				tq1[count1]=q[i];
				count1=count1+1;
			}
		}
		count1=count1-1;
		asort(tq1,count1);
		for(i=1;i<=n;i++)
		{
			if(q[i]<h)
			{
				tq2[count2]=q[i];
				count2=count2+1;
			}
		}
		count2=count2-1;
		dsort(tq2,count2);
		for(i=1;i<=count1;i++)
			tq[i]=tq1[i];
		tq[count1+1]=max;
		tq[count1+2]=0;
		for(i=1;i<=count2;i++)
			tq[count1+2+i]=tq2[i];
		tq[0]=h;
		printf("\n");
		for(i=0;i<n;i++)
		{
			if(tq[i+1]>tq[i])
				diff=tq[i+1]-tq[i];
			else
				diff=tq[i]-tq[i+1];
			seek=seek+diff;
			printf("\nHead moved from %d to %d with a seek of %d",tq[i],tq[i+1],diff);
		}
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			if(q[i]<h)
			{
				tq1[count1]=q[i];			
				count1=count1+1;
				
			}
		}
		count1=count1-1;
		dsort(tq1,count1);
		for(i=1;i<=n;i++)
		{
			if(q[i]>h)
			{
				tq2[count2]=q[i];			
				count2=count2+1;
	
			}
		}
		count2=count2-1;
		asort(tq2,count2);
		for(i=1;i<=count1;i++)
			tq[i]=tq1[i];
		tq[count1+1]=0;
		tq[count1+2]=max;
		for(i=1;i<=count2;i++)
			tq[count1+2+i]=tq2[i];
		tq[0]=h;
		printf("\n");
		for(i=0;i<=n;i++)
		{
			if(tq[i+1]>tq[i])
				diff=tq[i+1]-tq[i];
			else
				diff=tq[i]-tq[i+1];
			seek=seek+diff;
			printf("\nHead moved from %d to %d with a seek of %d",tq[i],tq[i+1],diff);
		}
	}
	printf("\nTotal seek time = %d",seek);
	aseek=seek/n;
	printf("\nAverage seek time = %d\n",aseek);
}

