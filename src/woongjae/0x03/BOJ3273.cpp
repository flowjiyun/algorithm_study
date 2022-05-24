#include <stdio.h>

int main()
{
    int n;
    int i;
    int x;
    int cnt;
    int j;

    cnt = 0;
    i = 0;
    scanf("%d", &n);
    int arr[n];
    while (i < n)
    {
        scanf("%d", &arr[i]);
        i++;
    }
    i = 0;
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[i] + arr [j]) == x)
                cnt++;
        }
    }

    printf("%d\n", cnt);
}