#include <stdio.h>
//A+B
int main()
{
    int a;
    int b;

    scanf("%d %d",&a,&b);
    if (!(a>0))
        return 0;
    if (!(b<10))
        return 0;
    printf("%d\n",a+b);
}