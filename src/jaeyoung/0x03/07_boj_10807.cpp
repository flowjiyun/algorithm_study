#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int i;
    int v;
    int num[100];
    int cnt;

    cnt = 0;
    cin >> n;
    i = 0;
    while (i < n)
        cin >> num[i++];
    cin >> v;
    i = 0;
    while (i < n)
    {
        if (num[i] == v)
            cnt++;
        i++;
    }
    cout << cnt;
}