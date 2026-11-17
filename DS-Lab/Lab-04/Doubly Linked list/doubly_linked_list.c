
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Display linked list
void display(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Forward: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Insert at left (beginning)
struct Node* insertLeft(struct Node *head) {
    struct Node *newNode;
    int value;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;

    return head;
}

// Delete a specific key
struct Node* deleteKey(struct Node *head) {
    struct Node *temp;
    int key;

    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    printf("Enter key to delete: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found\n");
        return head;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);

    printf("Key deleted successfully\n");

    return head;
}

int main() {
    struct Node *head = NULL;
    struct Node *newNode, *temp;
    int n, value, choice;

    // Creation
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter data: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {
            temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    while (1) {
        printf("\n--- DOUBLY LINKED LIST ---\n");
        printf("1. Insert at Left\n");
        printf("2. Delete a Specific Key\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                head = insertLeft(head);
                break;

            case 2:
                head = deleteKey(head);
                break;

            case 3:
                display(head);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
