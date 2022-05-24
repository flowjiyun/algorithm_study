#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[26] = {};
    fill(a, a+ 26, 0);
    string str;
    cin >> str;

    for (char c: str) {
        int tmp = c - 'a';
        a[tmp]++;
    }

    for (int i: a)
        cout << i << ' ';

    return (0);
}