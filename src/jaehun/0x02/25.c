#include <stdio.h>
//별 찍기 - 9
int main()
{
    int n;
    scanf("%d", &n);
    for (int y=1; y<=n; y++)
    {
        for (int x=1; x<y; x++)
            printf(" ");
        for (int x=y; x<=2*n-y; x++)
            printf("*");
        printf("\n");
    }
    for (int y=n+1; y<=2*n-1; y++)
    {
        for (int x=1; x<2*n-y; x++)
            printf(" ");
        for (int x=0; x<=2*y-2*n; x++)
            printf("*");
        printf("\n");
    }
}