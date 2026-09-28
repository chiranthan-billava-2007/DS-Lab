#include <stdio.h>

int linearSearch(int arr[], int n, int key)
{
    for (int index = 0; index < n; index++)
    {
        if (arr[index] == key)
        {
            return index;
        }
    }

    return -1;
}

int main()
{
    int arr[100];
    int n, key, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = linearSearch(arr, n, key);

    if (result == -1)
    {
        printf("Element not found in the array.\n");
    }
    else
    {
        printf("Element found at index %d.\n", result);
        printf("Position = %d\n", result + 1);
    }

    return 0;
}