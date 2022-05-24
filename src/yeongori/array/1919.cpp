#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string s1, s2;
    cin >> s1 >> s2;

    int arr[26] = {};
    for (char c: s1) arr[c - 'a']++;
    for (char c: s2) arr[c - 'a']--;

    int tmp = 0;
    for (int i: arr) {
        if (i > 0) tmp += i;
        if (i < 0) tmp += (-i);
    }

    cout << tmp << '\n';
    return (0);
}