#include <stdio.h>
//별 찍기 - 6
int main()
{
    int n;
    scanf("%d", &n);
    for (int y=1; y<=n; y++)
    {
        for (int i=n-1; i>n-y; i--)
        {
            printf(" ");
        }
        for (int x=2*n-2*y+1; x>=1; x--)
        {
            printf("*");
        }
        printf("\n");
    }
}