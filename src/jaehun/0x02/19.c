#include <stdio.h>
//별 찍기 - 3
int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        for (int j=n-i; j>=1; j--)
        {
            printf("*");
        }
        printf("\n");
    }
}