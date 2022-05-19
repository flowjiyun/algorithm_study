#include <stdio.h>
//세수정렬
int main()
{
    int a;
    int b;
    int c;
    int swap;

    swap = 0;
    scanf("%d %d %d", &a, &b, &c);
    if (!(1 <= a && a <= 1000000))
        return 0;
    if (!(1 <= b && b <= 1000000))
        return 0;
    if (!(1 <= c && c <= 1000000))
        return 0;
    if (a == b || a == c || b == c)
        return 0;
    if (a > b)
    {
        swap = a;
        a = b;
        b = swap;
    }
    if (b > c)
    {
        swap = b;
        b = c;
        c = swap;
    }
    if (a > b)
    {
        swap = a;
        a = b;
        b = swap;
    }
    printf("%d %d %d", a, b, c);
}