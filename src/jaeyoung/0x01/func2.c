int func2(int arr[], int N)
{
    int i;
    int j;

    i = 0;
    while (i < N)
    {
        j = i + 1;
        while (j < N)
        {
            if (arr[i] + arr[j] == 100)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
/*
#include <stdio.h>
 
int main()
{
    int arr1[] = {1, 52, 48};
    int arr2[] = {50, 42};
    int arr3[] = {4, 13, 63, 87};

    printf("%d \n", func2(arr1, 3));
    printf("%d \n", func2(arr2, 2));
    printf("%d \n", func2(arr3, 4));
}*/