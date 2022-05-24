#include <bits/stdc++.h>

using namespace std;

int main(void){
    int arr[10] = {};
    int n, max;
    cin >> n;
    while (n > 0){
        arr[n % 10]++;
        n /= 10;
    }

    int tmp = arr[6] + arr[9];
    arr[6] = tmp / 2;
    arr[6] += tmp % 2;
    arr[9] = 0;

    max = 1;
    for (int i: arr) {
        if (i > max)
            max = i;
    }
    cout << max << '\n';
}