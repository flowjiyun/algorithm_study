// X보다 작은 수
#include <stdio.h>

void check(int arr[], int N, int X)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] < X)
        {
            printf("%d ", arr[i]);
        }
    }
}
int main(void)
{
    int N, X;
    scanf("%d %d", &N, &X);
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    check(arr, N, X);
    return (0);
}