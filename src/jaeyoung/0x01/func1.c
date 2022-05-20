int func1(int N)
{
    int i;
    int sum;

    i = 1;
    sum = 0;
    while (i <= N)
    {
        if(i % 3 == 0 || i % 5 == 0)     
           sum += i;
        i++;    
    }
    return (sum);
}

/*
#include <stdio.h>

int main()
{
    printf("%d\n", func1(16));
    printf("%d\n", func1(34567));
    printf("%d", func1(27639));
}
*/