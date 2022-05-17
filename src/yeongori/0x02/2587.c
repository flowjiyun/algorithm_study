// 대표값2
#include <stdio.h>

int main(void)
{
    int n[5], total = 0;

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &n[i]);
        total += n[i];
    }
    total /= 5;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j < 5 - i; j++)
        {
            if (n[j - 1] > n[j])
            {
                int tmp = n[j];
                n[j] = n[j - 1];
                n[j - 1] = tmp;
            }
        }
    }
    printf("%d\n%d\n", total, n[2]);
    return (0);
}