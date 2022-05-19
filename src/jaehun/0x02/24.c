#include <stdio.h>
//별 찍기 - 8
int main()//x_len=2n, y_len=2n-1, *x_space=2n-*y, *x_space=2*y-2n
{
    int n;
    scanf("%d", &n);
    for (int y=1; y<=n; y++)
    {
        for (int x=1; x<=y; x++)
            printf("*");
        for (int x=y; x<2*n-y; x++)
            printf(" ");
        for (int x=2*n-y; x<2*n; x++)
            printf("*");
        printf("\n");
    }
    for (int y=n+1; y<=2*n-1; y++)
    {
        for (int x=1; x<=2*n-y; x++)
            printf("*");
        for (int x=1; x<=2*y-2*n; x++)
            printf(" ");
        for (int x=1; x<=2*n-y; x++)
            printf("*");
        printf("\n");
    }
}