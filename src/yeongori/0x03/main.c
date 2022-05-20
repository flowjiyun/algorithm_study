#include <stdio.h>

void insert(int idx, int num, int arr[], int len)
{
    int i;
    for (i = len - 1; idx != i; i--)
        arr[i] = arr[i - 1];

    arr[i] = num;
}

void erase(int idx, int arr[], int len)
{
    for (int i = 0; i < len - idx; i++)
    {
        arr[idx + i] = arr[idx + i + 1];
    }
}

void printArr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int main(void)
{
    int arr[10] = {2, 4, 7, 6, 8, 9, 3, 5, 0};
    insert(3, -1, arr, 10);
    printArr(arr, 10);
    erase(3, arr, 10);
    printArr(arr, 10);
}