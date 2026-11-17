
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


struct Node* push(struct Node *top) {
    struct Node *newNode;
    int value;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return top;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = top;

    top = newNode;

    return top;
}


struct Node* pop(struct Node *top) {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack Underflow\n");
        return top;
    }

    temp = top;

    printf("Deleted element: %d\n", temp->data);

    top = top->next;

    free(temp);

    return top;
}


void display(struct Node *top) {
    struct Node *temp = top;

    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements:\n");

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node *top = NULL;
    int choice;

    while (1) {
        printf("\n--- STACK OPERATIONS ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                top = push(top);
                break;

            case 2:
                top = pop(top);
                break;

            case 3:
                display(top);
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

