int func4(int N)
{
    int n;

    n = 1;
    while (n <= N / 2)
    {
        n *= 2;
    }
    return (n);
}
/*
#include <stdio.h>

int main()
{
    printf("%d \n", func4(1));
    printf("%d \n", func4(1025));
    printf("%d \n", func4(252341));
}*/