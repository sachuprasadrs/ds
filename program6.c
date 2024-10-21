#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* front = NULL;
struct node* rear = NULL;

void enq(int item);
void deq();
void display();

int main()
{
	int n, choice;
	printf("\nQueue using linked list\n");
	printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
    
	do
	{
		printf("\nEnter your choice:\t");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
			printf("Enter the element:\t");
			scanf("%d", &n);
			enq(n);
			break;
			case 2:
			deq();
			break;
			case 3:
			display();
			break;
			case 4:
			printf("Exiting..\n");
			break;
			default:
			printf("Invalid Choice\n");
			break;
		}
	}while(choice != 4);
	return 0;
}

void enq(int element)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = element;
	newNode->link = NULL;

	if (rear == NULL)
	{
		front = rear = newNode;
	}
	else 
	{
		rear->link = newNode;
		rear = newNode;
	}
	printf("Enqueued: %d\n", element);
}

void deq()
{
	if (front == NULL)
	{
		printf("Queue is empty. Cannot dequeue.\n");
		return;
	}
	struct node* temp = front;
	int dequeuedData = front->data;
	front = front->link;
	
	if (front == NULL)
	{
		rear = NULL;
	}
	free(temp);
	printf("Dequeued: %d\n", dequeuedData);
}

void display()
{
	if (front == NULL)
	{
		printf("Queue is empty.\n");
		return;
	}
	struct node* current = front;
	printf("Queue elements:\n");
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->link;
	}
	printf("\n");
}

