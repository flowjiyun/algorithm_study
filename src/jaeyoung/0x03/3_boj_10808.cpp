#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    string alph = "abcdefghijklmnopqrstuvwxyz";
    int i;
    int j;
    int len;
    int num[26];

    cin >> s;
    i = 0;
    while (i < 26)
        num[i++] = 0;
    len = 0;
    while (s[len])
        len++;
    i = 0;
    while (i < len)
    {
        j = 0;
        while (j < 26)
        {
            if (s[i] == alph[j])
                num[j] += 1;
            j++;
        }
        i++;
    }
    i = 0;
    while (i < 26)
    {
        cout << num[i] << ' ';
        i++;
    }
}