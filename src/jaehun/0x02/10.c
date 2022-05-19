#include <stdio.h>
//홀수
int main()
{
    int i = 0;
    int n;
    int sum = 0;
    int min = 99;

    while (i < 7)
    {
        scanf("%d", &n);
        if (n % 2 == 1)
        {
            sum += n;
            if (n < min)
                min = n;
        }
        i++;
    }
    if (sum == 0)
    {
        printf("-1");
        return 0;
    }
    else
    {
        printf("%d\n%d\n", sum, min);
    }
}