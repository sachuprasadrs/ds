#include<stdio.h>
void main()
{
	int stack[50],top=-1,a,ch,i,d,z,size;
	void push(int a)
	{
		if(top==size-1)
		{
			printf("\n Stack is overflow !!!");
		}
		else
		{
			top++;
			stack[top]=a;
			printf("\nSuccessfully Inserted\n");
		}
	}
	void pop()
	{
		if(top==-1)
		{
			printf("Stack Underflow !!!");
		}
		else
		{
			d=stack[top];
			top--;
			printf("Popped value is: %d",d);
		}
	}	
	void display()
	{
		if(top==-1)
		{
			printf("Stack Empty\n");
		}
		else
		{
			printf("Stack Elements are:\n");
			for(i=0;i<=top;i++)
			{
				printf("\n %d",stack[i]);
			}
		}
	}
	printf("Enter size of stack\n");
	scanf("%d",&size);
	do
	{
		printf("\nSelect any option:\n1.Push\n2.pop\n3.display\n4.exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element to push\n");
				scanf("%d",&a);
				push(a);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			default:
				printf("\n Invalid Coice");
				break;
		}
		
	}while(ch<4);
}
