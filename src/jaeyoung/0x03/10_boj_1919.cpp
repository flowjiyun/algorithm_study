#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[26] = {};
    int cnt;
    int i;
    
    i = 0;
    cnt = 0;
    string s1, s2;

    cin >> s1 >> s2;
   
    for (auto c : s1)
        arr[c - 'a']++;
    for (auto c : s2)
        arr[c - 'a']--;
    for (auto c : arr)
    {
        if (c < 0)
            c *= -1;
        cnt += c;
    }
    cout << cnt;
}
