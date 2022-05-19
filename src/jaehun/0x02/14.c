#include <stdio.h>
//핸드폰 요금
int main()
{
    int n;
    scanf("%d", &n);
    int arr[20];
    int Y = 0;
    int M = 0;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        Y += arr[i]/30 + 1;
        M += arr[i]/60 + 1;
    }
    Y *= 10;
    M *= 15;
    if (Y == M)
        printf("Y M %d", Y);
    else if (M > Y)
        printf("Y %d", Y);
    else if (Y > M)
        printf("M %d", M);
}