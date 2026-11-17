
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


void enqueue(struct Node **front, struct Node **rear) {
    struct Node *newNode;
    int value;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (*front == NULL) {
        *front = newNode;
        *rear = newNode;
    }
    else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}


void dequeue(struct Node **front, struct Node **rear) {
    struct Node *temp;

    if (*front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    temp = *front;

    printf("Deleted element: %d\n", temp->data);

    *front = (*front)->next;

    if (*front == NULL) {
        *rear = NULL;
    }

    free(temp);
}


void display(struct Node *front) {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements:\n");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *front = NULL;
    struct Node *rear = NULL;
    int choice;

    while (1) {
        printf("\n--- QUEUE OPERATIONS ---\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                enqueue(&front, &rear);
                break;

            case 2:
                dequeue(&front, &rear);
                break;

            case 3:
                display(front);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}

