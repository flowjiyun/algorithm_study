// 최댓값
#include <stdio.h>

int main(void)
{
    int n[9];
    int max = 0, idx;
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &n[i]);
        if (n[i] > max)
        {
            max = n[i];
            idx = i + 1;
        }
    }

    printf("%d\n%d\n", max, idx);
    return (0);
}