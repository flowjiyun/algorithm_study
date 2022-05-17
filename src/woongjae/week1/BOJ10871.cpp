#include <stdio.h>

int main()
{
    int n, x;
    int a[10000];
    int i;

    i = 0;
    scanf("%d %d", &n, &x);
    while (i < n)
    {
        scanf("%d", &a[i]);
        i++;
    }
    i = 0;

    while (i < n)
    {
        if (a[i] < x)
            printf("%d ", a[i]);
        i++;
    }
    printf("\n");
    return (0);
}