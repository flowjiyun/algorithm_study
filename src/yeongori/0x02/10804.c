// 카드 역배치
#include <stdio.h>

void swap(int card[], int start, int end)
{
    int loop = end - start + 1;
    if (end == start)
        return;

    for (int i = 0; i < loop / 2; i++)
    {
        int tmp = card[start + i];
        card[start + i] = card[end - i];
        card[end - i] = tmp;
    }
}

int main(void)
{
    int card[21];
    for (int i = 0; i < 21; i++)
        card[i] = i;

    int start, end;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d %d", &start, &end);
        swap(card, start, end);
    }

    for (int i = 1; i < 21; i++)
        printf("%d ", card[i]);

    return (0);
}