#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int size, x, res = 0;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) cin >> arr[i];
    cin >> x;

    int num[x + 1] = {};

    for (int i: arr) {
        if (x - i > 0) {
            if (num[x - i])
                res++;
            num[i] = 1;
        }
    }
    cout << res << '\n';
    return 0;
}