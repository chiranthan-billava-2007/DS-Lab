#include <stdio.h>

int insertElement(int arr[], int n, int capacity, int position, int element)
{
    if (n >= capacity)
    {
        printf("Error: Array Overflow - Maximum capacity reached\n");
        return n;
    }

    if (position < 0 || position > n)
    {
        printf("Error: Invalid Position specified\n");
        return n;
    }

    
    for (int i = n; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    n++;

    return n;
}

int deleteElement(int arr[], int n, int position)
{
    if (n <= 0)
    {
        printf("Error: Array Underflow - Array is empty\n");
        return n;
    }

    if (position < 0 || position >= n)
    {
        printf("Error: Invalid Position specified\n");
        return n;
    }

    
    for (int i = position; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    return n;
}

void display(int arr[], int n)
{
    printf("Array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int capacity = 100;
    int arr[100];
    int n, position, element;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    display(arr, n);

    
    printf("\nEnter position for insertion (0-based): ");
    scanf("%d", &position);

    printf("Enter element to insert: ");
    scanf("%d", &element);

    n = insertElement(arr, n, capacity, position, element);

    printf("After insertion:\n");
    display(arr, n);

    
    printf("\nEnter position for deletion (0-based): ");
    scanf("%d", &position);

    n = deleteElement(arr, n, position);

    printf("After deletion:\n");
    display(arr, n);

    return 0;
}