#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    int alpha1[26] = {0};
    int alpha2[26] = {0};
    int i;
    int cnt;

    cin >> a >> b;
    i = 0;
    while (a[i])
    {
        alpha1[a[i] - 'a']++;
        i++;
    }
    i = 0;
    while (b[i])
    {
        alpha2[b[i] - 'a']++;
        i++;
    }
    i = 0;
    cnt = 0;
    while (i < 26)
    {
        if(alpha1[i] != alpha2[i])
            cnt += abs(alpha1[i] - alpha2[i]);
        i++;
    }
    cout << cnt;

    return (0);
}