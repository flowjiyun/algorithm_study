#include <stdio.h>
//사칙연산
int main()
{
    int a;
    int b;

    scanf("%d %d", &a, &b);
    if (!(1 <= a))
        return 0;
    if (!(b <= 10000))
        return 0;
    printf("%d\n",a+b);
    printf("%d\n",a-b);
    printf("%d\n",a*b);
    printf("%d\n",a/b);
    printf("%d\n",a%b);
}