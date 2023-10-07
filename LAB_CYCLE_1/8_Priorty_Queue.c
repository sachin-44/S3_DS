
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data,prio;
	struct node *link;
}; struct node *front=NULL;

void endq() ;
void deq();
void display();

int main()
{
 int choice;
 
 
 
  
 while(1)
	{
	printf(" 1.endqueue\n 2.dequeue\n 3.display\n 4.exit\n Enter the choice:");
	scanf("%d",&choice);
	switch(choice)
	{
	  case 1:
		
		
		endq();
		break;
	  case 2:
		deq();
		break;
	  case 3:
		display();
		break;
	  case 4:exit(0);
	  default:printf("invalid choice\n");
			break;
		
	}
	}
}
//CSL201 DATA STRUCTURES LAB ----- DEION TOMSON
void endq()
{	int p;
	struct node *new,*temp;
	new=(struct node *)malloc(sizeof(struct node));
	new->link=NULL;
	printf("enter data:");
	scanf("%d",&new->data);
	printf("enter priority:");
	scanf("%d",&p);
	new->prio=p;
	if(front==NULL)
	{
		front=new;
	}
	else if(p<(front->prio))
	{
		new->link=front;
		front=new;
	}
	else
	{
		temp=front;
		while(temp->link!=NULL)
		{
			if((temp->link->prio)<=p)
				temp=temp->link;
			else
				break;
		}
		if(temp->link==NULL)
		{
			temp->link=new;
		}
		else
			{new->link=temp->link;
			temp->link=new;}
	}
	
}

void deq()
{
	struct node *temp;
	if (front==NULL)
    	printf("under flow\n");
 
 	
     else
	{
		temp=front;
		printf("dequed element:%d\n",temp->data);
		front=front->link;
		free(temp);

	}
}
void display()
{
		if(front==NULL)
			printf("queue empty\n");
		else
			{
				struct node *temp=front;
				while(temp!= NULL)
				{
					printf("data :%d priority:%d\n",temp->data,temp->prio);
					temp=temp->link;		
				}

			}


}
