#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;


void insert()
{
    int item;

    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &item);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = item;

    printf("%d inserted into queue\n", item);
}


void delete()
{
    int item;

    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }

    item = queue[front];
    front++;

    printf("%d deleted from queue\n", item);


    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}


void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue Empty\n");
        return;
    }

    printf("Queue elements: ");

    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main()
{
    printf("Chiranthan    1WA25CS061    2026-10-06\n");
    int choice;

    while (1)
    {
        printf("\n--- LINEAR QUEUE ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
