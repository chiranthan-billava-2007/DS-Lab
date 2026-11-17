
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


struct Node* concatenate(struct Node *head1, struct Node *head2) {

    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    struct Node *temp = head1;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head2;

    return head1;
}

int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *newNode, *temp;
    int n, value;


    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL)
            return 1;

        printf("Enter data: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head1 == NULL) {
            head1 = newNode;
        }
        else {
            temp = head1;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }


    printf("\nEnter number of nodes in second list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL)
            return 1;

        printf("Enter data: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head2 == NULL) {
            head2 = newNode;
        }
        else {
            temp = head2;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    printf("\nFirst Linked List:\n");
    display(head1);

    printf("Second Linked List:\n");
    display(head2);


    head1 = concatenate(head1, head2);

    printf("\nConcatenated Linked List:\n");
    display(head1);

    return 0;
}

