// 별 찍기 - 9
#include <stdio.h>

void print(int cnt, int n)
{

    int sp = n - cnt;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        if (sp == 0 && i > cnt + n - 2)
            ;
        else if (sp == 0)
            printf("*");
        else
        {
            printf(" ");
            sp--;
        }
    }
    printf("\n");
}

void recursive(int cnt, int n)
{
    if (cnt == 0)
        return;
    print(cnt, n);
    recursive(--cnt, n);
    if (++cnt > 0)
        print(++cnt, n);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    recursive(n, n);
}