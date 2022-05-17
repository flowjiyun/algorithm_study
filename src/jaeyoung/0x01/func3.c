int func3(int N)
{
    int n;

    n = 1;
    while (n <= N / n)
    {
        if (n == N / n && N % n == 0)
            return (1);
        n++;
    }
    return (0);
}
/*
#include <stdio.h>

int main()
{
    printf("%d \n", func3(9));
    printf("%d \n", func3(693953651));
    printf("%d \n", func3(756580036));
}*/