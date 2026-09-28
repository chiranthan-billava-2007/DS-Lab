/*
Question 3: Searching Algorithms - Binary Search

Aim:
To find the position of a target key in an array
using Binary Search.

Note:
The array must be sorted in ascending order.
*/

#include <stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[100], n, key, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in ascending order:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, n, key);

    if (result == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at position %d\n", result + 1);
    }

    return 0;
}