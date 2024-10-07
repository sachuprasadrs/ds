#include<stdio.h>
void enq();
void deq();
void disp();
int q[100],rear=-1,front=-1,ch,n;
void main()
{
	printf("\nEnter the no of elements in queue\n");
	scanf("%d",&n);
	do
	{
		printf("\nQueue operations\n1.Enqueue\n2.Dequeue\n3.Traversal\n4.Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enq();
				break;
			case 2:deq();
				break;
			case 3:disp();
				break;
			default:printf("\nInvalid choice\n");
		}
	}while(ch<4);
}
void enq()
{
	int item;
	if(rear==n-1)
	{
		printf("Queue is full\n");
	}
	else
	{
		printf("Enter item to be inserted:\n");
		scanf("%d",&item);
		if((rear==-1) && (front==-1))
		{
			front=0;
		}
		rear=rear+1;
		q[rear]=item;
		disp();
	}
}	
void deq()
{
	int i;
	if(front==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		i=q[front];
		if(rear==front)
		{
			rear=-1;
			front=-1;
		}
		else
		{
			front=front+1;
		}
		disp();
	}
}
void disp()
{
	int j;
	if((front==-1)&&(rear==-1))
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("The Queue is\n");
		for(j=front;j<=rear;j++)
		{
			printf("%d\t",q[j]);
		}
	}
}
