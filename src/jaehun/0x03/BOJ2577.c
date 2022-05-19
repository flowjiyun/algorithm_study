//숫자의 개수
#include <stdio.h>
int main() {
    int A, B, C, number;
    int arr[10] = {};
    scanf("%d %d %d", &A, &B, &C);
    for (number=A*B*C; number>9; number/=10)
        arr[number%10]++;
    if (number<10)
        arr[number]++;
    for (int i=0; i<10; i++)
        printf("%d\n", arr[i]);
}