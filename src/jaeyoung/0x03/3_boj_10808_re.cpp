//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int num[26] = {};

    cin >> s;
    for (auto c : s)
        num[c - 'a']++;
    for (auto c : num)
        cout << c << ' ';
}