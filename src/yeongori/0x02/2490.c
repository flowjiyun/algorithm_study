// 윷놀이
#include <stdio.h>

int main(void)
{
    int cnt, n;
    char c[3];

    for (int i = 0; i < 3; i++)
    {
        cnt = 0;
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &n);
            if (n == 0)
                cnt++;
        }
        if (cnt == 0)
            c[i] = 'E';
        else if (cnt == 1)
            c[i] = 'A';
        else if (cnt == 2)
            c[i] = 'B';
        else if (cnt == 3)
            c[i] = 'C';
        else
            c[i] = 'D';
    }

    for (int i = 0; i < 3; i++)
        printf("%c\n", c[i]);
    return (0);
}