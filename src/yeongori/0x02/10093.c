// 숫자
#include <stdio.h>

int main(void)
{
    unsigned long long A, B, cnt;
    scanf("%llu %llu", &A, &B);

    if (A > B)
    {
        cnt = A - B - 1;
        printf("%llu\n", cnt);
        while (A > ++B)
        {
            printf("%llu ", B);
        }
    }
    else if (B > A)
    {
        cnt = B - A - 1;
        printf("%llu\n", cnt);
        while (B > ++A)
        {
            printf("%llu ", A);
        }
    }
    else
    {
        printf("0\n");
    }
    return (0);
}