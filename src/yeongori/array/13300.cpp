#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N, K, S, Y, total = 0;
    cin >> N >> K;

    int arr[2][7] = {};

    for (int i = 0; i < N; i++) {
        cin >> S >> Y;
        if (S == 0)
            arr[0][Y]++;
        if (S == 1)
            arr[1][Y]++;
    }

    for (int i = 1; i < 7; i++) {
        if (arr[0][i] > 0) {
            total += arr[0][i] / K;
            if (arr[0][i] % K)
                total++;
        }
        if (arr[1][i] > 0) {
            total += arr[1][i] / K;
            if (arr[1][i] % K)
                total++;
        }
    }

    cout << total << '\n';
}