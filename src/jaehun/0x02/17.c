#include <stdio.h>
//별 찍기 - 1
int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<=i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}