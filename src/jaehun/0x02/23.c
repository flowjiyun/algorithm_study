#include <stdio.h>
//별 찍기 - 7
int main()
{
        int n;
    scanf("%d", &n);
    for (int y=1; y<=n; y++)
    {
        for (int i=0; i<n-y; i++)
        {
            printf(" ");
        }
        for (int x=1; x<=2*y-1; x++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int y=n; y>1; y--)
    {
        for (int i=n; i>=y; i--)
        {
            printf(" ");
        }
        for (int x=2*y-3; x>=1; x--)
        {
            printf("*");
        }
        printf("\n");
    }
}