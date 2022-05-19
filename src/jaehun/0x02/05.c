#include <stdio.h>
//시험성적
int main()
{
    int a;
    
    scanf("%d", &a);
    if (90 <= a && a <= 100)
        printf("A");
    else if (80 <= a && a <= 89)
        printf("B");
    else if (70 <= a && a <= 79)
        printf("C");
    else if (60 <= a && a <= 69)
        printf("D");
    else if (0 <= a && a <= 59)
        printf("F");
    return 0;
}