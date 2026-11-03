#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create linked list
void create()
{
    int n, i;
    struct node *newnode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }
}

// Delete first node
void deleteAtFirst()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);

    printf("First node deleted successfully.\n");
}

// Delete node at specified index (Zero-based)
void deleteAtPosition()
{
    int pos, i;
    struct node *temp, *prev;

    printf("Enter position (index): ");
    scanf("%d", &pos);

    if(head == NULL || pos < 0)
    {
        printf("Invalid position.\n");
        return;
    }

    if(pos == 0)
    {
        deleteAtFirst();
        return;
    }

    temp = head;

    for(i = 0; i < pos; i++)
    {
        if(temp == NULL)
        {
            printf("Invalid position.\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;

    free(temp);

    printf("Node deleted successfully.\n");
}

// Delete last node
void deleteAtEnd()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Last node deleted successfully.\n");
        return;
    }

    temp = head;

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    printf("Last node deleted successfully.\n");
}

// Display linked list
void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    int choice;

    printf("Chiranthan    1WA25CS061    03/11/2026\n");

    while(1)
    {
        printf("\n--- SINGLY LINKED LIST ---\n");
        printf("1. Create Linked List\n");
        printf("2. Delete First Node\n");
        printf("3. Delete Node at Specified Position\n");
        printf("4. Delete Last Node\n");
        printf("5. Display Linked List\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                deleteAtFirst();
                break;

            case 3:
                deleteAtPosition();
                break;

            case 4:
                deleteAtEnd();
                break;

            case 5:
                display();
                break;

            case 0:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
