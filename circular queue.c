#include <stdio.h>

void enq();
void deq();
void disp();
int q[100], rear = -1, front = -1, ch, n;

void main() {
    printf("\nEnter the number of elements in the circular queue (max 100)\n");
    scanf("%d", &n);
    
    do {
        printf("\nQueue operations\n1.Enqueue\n2.Dequeue\n3.Traversal\n4.Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                enq();
                break;
            case 2:
                deq();
                break;
            case 3:
                disp();
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    } while (ch != 4);
}

void enq() {
    int value;
    
    if ((rear + 1) % n == front) { // Check if the queue is full
        printf("\nQueue is full. Cannot enqueue %d.\n", value);
        return;
    }

    printf("Enter the value to enqueue: ");
    scanf("%d", &value);

    if (front == -1) { // Queue is empty
        front = 0;
    }
    
    rear = (rear + 1) % n; // Circular increment
    q[rear] = value; // Insert the element
    printf("Enqueued: %d\n", value);
}

void deq() {
    if (front == -1) { // Check if the queue is empty
        printf("\nQueue is empty. Cannot dequeue.\n");
        return;
    }

    int value = q[front];
    if (front == rear) { // Queue has only one element
        front = rear = -1; // Reset the queue
    } else {
        front = (front + 1) % n; // Circular increment
    }
    
    printf("Dequeued: %d\n", value);
}

void disp() {
    if (front == -1) { // Check if the queue is empty
        printf("\nQueue is empty.\n");
        return;
    }

    printf("Circular Queue: ");
    int i = front;
    while (1) {
        printf("%d ", q[i]);
        if (i == rear) break; // Stop when we reach the rear
        i = (i + 1) % n; // Circular increment
    }
    printf("\n");
}

