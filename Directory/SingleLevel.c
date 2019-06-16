#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NODE
{
	char name[20];
	struct NODE *link;
};
void main()
{
	char name[20];int ch;char temp[20];int flag;
	struct NODE *ptr,*ptr1;
	struct NODE *HEADER;struct NODE *new1;
	printf("Enter the name of the directory ");
	scanf("%s",name);
	HEADER=(struct NODE*)malloc(sizeof(struct NODE));
	strcpy(HEADER->name,name);	
	HEADER->link=NULL;
	while(1)
	{
		printf("\nPress\n1.Add a file \n2.Remove a file \n3.Display all files \n4.Exit \n");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter the name of the file ");
			scanf("%s",temp);
			new1=(struct NODE*)malloc(sizeof(struct NODE));
			strcpy(new1->name,temp);
			ptr=HEADER;
			while(ptr->link!=NULL)
				ptr=ptr->link;
			new1->link=NULL;
			ptr->link=new1;
			printf("\nFile Added\n");
		}
		else if(ch==2)
		{
			printf("\nEnter the name of the file to be deleted ");
			scanf("%s",temp);
			flag=0;
			ptr=HEADER;			
			ptr1=HEADER;
			while(ptr->link!=NULL)
			{
				ptr1=ptr;
				ptr=ptr->link;
				if(strcmp(temp,ptr->name)==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
				printf("\nFile not found");
			else
			{
				ptr1->link=ptr->link;
				printf("\nFile has been deleted");
			}
		}
		else if(ch==3)
		{
			printf("\nName of directory: %s",HEADER->name);
			printf("\n\nFiles\n\n");
			ptr=HEADER->link;
			while(ptr!=NULL)
			{
				printf("%s\n",ptr->name);
				ptr=ptr->link;			
			}
		}
		else if(ch==4)
			break;
		else
			printf("Wrong Input");
	}
}
