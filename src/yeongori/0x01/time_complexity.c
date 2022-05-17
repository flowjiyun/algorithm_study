#include <stdio.h>

int func1(int N) {
    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0 || i % 5 == 0)
            result += i;
    }
    return (result);
}

int func2(int arr[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] + arr[j] == 100)
                return (1);
        }
    }
    return (0);
}

int func3(int N) {
    for (int i = 0; i * i <= N; i++) {
        if (i * i == N)
            return (1);
    }
    return (0);
}

int func4(int N) {
    if (N % 2 == 1)
        N--;
    for (int i = N; N > 0; N -= 2) {
        i = N;
        while (i >= 0) {
            if (i % 2 == 1)
                break;
            i /= 2;
        }
        if (i == 1)
            return (N);
    }
    return (0);
}

/*
int func4(int N) {
    int val = 1;
    while (2 * val <= N) {
        val *= 2;
    }
    return (val);
}
*/

int main()
{
    int arr[4]= {4, 13, 63, 86};

    printf("%d\n", func1(27639));
    printf("%d\n", func2(arr, 4));
    printf("%d\n", func3(756580036));
    printf("%d\n", func4(1024));

    return (0);
}

