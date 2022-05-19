#include <stdio.h>
//최댓값
int main()
{
    int arr[9];
    int max=1;
    int *a;
    for(int i=0; i<9; i++)
    {
        scanf("%d", &arr[i]);
        if (max < arr[i])
        {
            max = arr[i];
            a = i+1;
        }
    }
    printf("%d\n%d", max, a);
}