// 백설공주와 일곱난쟁이
#include <stdio.h>

void print(int *len, int *spy)
{
    for (int i = 0; i < 9; i++)
    {
        if (len[i] != spy[0] && len[i] != spy[1])
            printf("%d\n", len[i]);
    }
}

int main(void)
{
    int len[9], total = 0;
    int spy[2];

    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &len[i]);
        total += len[i];
    }

    total -= 100;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 1; j < 9 - i; j++)
        {
            if (len[j - 1] > len[j])
            {
                int tmp = len[j];
                len[j] = len[j - 1];
                len[j - 1] = tmp;
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (len[i] + len[j] == total)
            {
                spy[0] = len[i];
                spy[1] = len[j];
                print(len, spy);
                return (0);
            }
        }
    }

    return (0);
}