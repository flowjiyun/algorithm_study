//방 번호
#include <stdio.h>
int main() {
    //가장 많이 필요한 숫자만큼 세트가 필요
    //6과 9는 더한 후 2로 나눈만큼 세트가 필요
    //6과 9 제외, max를 구한 후, 6과 9를 더하고 2로 나눈 후 max와 비교
    int arr[10] = {};
    int number;
    int max = 0;
    int sixnine;
    scanf("%d", &number);
    for (number; number>9; number/=10)
        arr[number%10]++;
    if (number<10)
        arr[number]++;
    for (int i=0; i<10; i++) {
        if (arr[i] > max && i != 6 && i != 9)
            max = arr[i];
    }
    sixnine = (arr[6]+arr[9])/2 + (arr[6]+arr[9])%2;
    if (sixnine > max)
        max = sixnine;
    printf("%d", max);
}