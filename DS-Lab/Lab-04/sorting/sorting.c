
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void display(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void bubbleSort(struct Node *head) {
    struct Node *temp;
    int swapped;

    if (head == NULL)
        return head;

    do {
        swapped = 0;
        temp = head;

        while (temp->next != NULL) {

            if (temp->data > temp->next->data) {

                int t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;

                swapped = 1;
            }

            temp = temp->next;
        }

    } while (swapped);
}

int main() {
    struct Node *head = NULL;
    struct Node *newNode, *temp;
    int n, value;

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
        }
    }

    printf("\nOriginal Linked List:\n");
    display(head);

    bubbleSort(head);

    printf("\nSorted Linked List:\n");
    display(head);

    return 0;
}
