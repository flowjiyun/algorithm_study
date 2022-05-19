#include <stdio.h>
//윷놀이
int main()
{
    int a;
    int b;
    int c;
    int d;
    int q;
    int w;
    int e;

    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (!((0 <= a && a <= 1) || (0 <= b && b <= 1) ||
    (0 <= c && c <= 1) || (0 <= d && d <= 1)))
        return 0;
    q = a + b + c + d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (!((0 <= a && a <= 1) || (0 <= b && b <= 1) ||
    (0 <= c && c <= 1) || (0 <= d && d <= 1)))
        return 0;
    w = a + b + c + d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (!((0 <= a && a <= 1) || (0 <= b && b <= 1) ||
    (0 <= c && c <= 1) || (0 <= d && d <= 1)))
        return 0;
    e = a + b + c + d;
    if (q == 4)
        printf("E\n");
    else if (q == 3)
        printf("A\n");
    else if (q == 2)
        printf("B\n");
    else if (q == 1)
        printf("C\n");
    else if (q == 0)
        printf("D\n");
    if (w == 4)
        printf("E\n");
    else if (w == 3)
        printf("A\n");
    else if (w == 2)
        printf("B\n");
    else if (w == 1)
        printf("C\n");
    else if (w == 0)
        printf("D\n");
    if (e == 4)
        printf("E\n");
    else if (e == 3)
        printf("A\n");
    else if (e == 2)
        printf("B\n");
    else if (e == 1)
        printf("C\n");
    else if (e == 0)
        printf("D\n");
}