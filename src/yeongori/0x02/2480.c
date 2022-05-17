// 주사위 세개
#include <stdio.h>

int main(void)
{
    int s[3];
    int max = 0;

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &s[i]);
        if (s[i] > max)
            max = s[i];
    }

    if (s[0] == s[1] && s[1] == s[2])
        printf("%d\n", 10000 + (max * 1000));
    else if (s[0] == s[1] || s[0] == s[2])
        printf("%d\n", 1000 + (s[0] * 100));
    else if (s[1] == s[2])
        printf("%d\n", 1000 + (s[1] * 100));
    else
        printf("%d\n", max * 100);

    return (0);
}