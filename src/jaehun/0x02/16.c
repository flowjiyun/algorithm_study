#include <stdio.h>
//빠른 A+B
int main()
{
    int T;
    int A, B;
    scanf("%d", &T);
    for (int i=0; i<T; i++)
    {
        scanf("%d %d", &A, &B);
//    for (int j=0; j<T; j++)
        printf("%d\n", A+B);
    }
}