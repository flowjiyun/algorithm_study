#include <stdio.h>
//윤년
int main()
{
    int a;

    scanf("%d", &a);
    if (!(1 <= a && a <= 4000))
        return 0;        
    if (a % 4 != 0)
        printf("0");
    else if (a % 400 == 0)
        printf("1");
    else if (a % 100 == 0)
        printf("0");
    else
        printf("1");
}