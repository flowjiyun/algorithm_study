// 핸드폰 요금
#include <stdio.h>

int main(void)
{
    int call, Y_price = 0, M_price = 0;

    scanf("%d", &call);
    int time[call];
    for (int i = 0; i < call; i++)
    {
        scanf("%d", &time[i]);
        Y_price += time[i] / 30 + 1;
        M_price += time[i] / 60 + 1;
    }

    Y_price *= 10;
    M_price *= 15;
    if (Y_price == M_price)
        printf("Y M %d\n", Y_price);
    else if (Y_price > M_price)
        printf("M %d\n", M_price);
    else if (Y_price < M_price)
        printf("Y %d\n", Y_price);

    return (0);
}