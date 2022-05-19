#include <stdio.h>
//대표값
int main()
{
    int sum=0;
    int arr[5];
    int tmp=0;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    for (int j=0; j<5; j++)
    {
        for (int l=j+1; l<5; l++)
        {
            if (arr[j] > arr[l])
            {
                tmp = arr[j];
                arr[j] = arr[l];
                arr[l] = tmp;
            }
        }
    }
    printf("%d\n%d", sum/5, arr[2]);
}