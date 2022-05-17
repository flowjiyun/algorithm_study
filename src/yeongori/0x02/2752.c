// 세수정렬
#include <stdio.h>

int main(void)
{
    int n[3];

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &n[i]);
        if (i > 0 && n[i - 1] > n[i])
        {
            int tmp = n[i];
            n[i] = n[i - 1];
            n[i - 1] = tmp;
        }
        if (i > 1 && n[i - 2] > n[i - 1])
        {
            int tmp = n[i - 1];
            n[i - 1] = n[i - 2];
            n[i - 2] = tmp;
        }
    }

    for (int i = 0; i < 3; i++)
        printf("%d ", n[i]);
}