#include  <stdio.h>
int main() {
    int n, arr[10] = { 0, };
    scanf("%d", &n);
    while (n != 0) {
        arr[n % 10]++;
        n /= 10;
    }
    int temp = (arr[6] + arr[9] + 1) / 2;  
    for (int i = 0; i < 10; i++) {
            if (i == 6 || i == 9)
                continue;
            if (arr[i] >= temp)
                temp = arr[i];
        }
    if (temp == 0)
        temp = 1;
    printf("%d", temp);
    return 0;

}

