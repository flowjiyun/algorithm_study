
#include <bits/stdc++.h>
#include <utility>
#include <iostream>
using namespace std;
int arr[1000000];

int main()
{
    stack<pair<int, int>> num;
    fill(arr, arr + 1000000, -1);
    int n;
    cin >> n;

    int tar;
    for (int i = 0; i < n; i++) {
        cin >> tar;

        while (!num.empty() && num.top().first < tar) {
            arr[num.top().second] = tar;
            num.pop();
        }

        num.push({tar, i});
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
