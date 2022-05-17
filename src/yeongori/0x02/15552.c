// 빠른 A + B
#include <stdio.h>

int main(void)
{
    int test_cnt, a, b;
    scanf("%d", &test_cnt);
    int c[test_cnt];
    for (int i = 0; i < test_cnt; i++)
    {
        scanf("%d %d", &a, &b);
        c[i] = a + b;
    }

    for (int i = 0; i < test_cnt; i++)
        printf("%d\n", c[i]);
}