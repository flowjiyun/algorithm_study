#include <stdio.h>
//별 찍기 - 2
int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        for (int l=1; l<n-i; l++)
        {
            printf(" ");
        }
        for (int j=0; j<=i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}