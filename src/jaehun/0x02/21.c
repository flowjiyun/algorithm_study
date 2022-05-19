#include <stdio.h>
//별 찍기 - 5
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
}