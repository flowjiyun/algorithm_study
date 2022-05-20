#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int k;
    int s[1000];
    int y[1000];
    int m[6] = {};
    int w[6] = {};
    int i;
    int j;
    int cnt;

    cnt = 0;
    cin >> n >> k;
    i = 0;
    while (i < n)
        cin >> s[i] >> y[i++];
    i = 0;
    while (i < n)
    {
        if (s[i] < 0 || s[i] > 1)
            return (0);
        i++;
    }
    i = 0;
    while (i < n)
    {
        j = 1;
        while (j < 7)
        {
            if (s[i] && y[i] == j)
                m[j - 1]++;
            if (!s[i] && y[i] == j)
                w[j - 1]++;
            j++;
        }
        i++;
    }
    i = 0;
    while (i < 6)
    {
      //  cnt += ((m[i]) / k) + (m[i] % k) + ((w[i]) / k) + (w[i] % k);
      //  i++;
        if (m[i] > k)
        cnt += ((m[i] - 1) / k) + 1;
        else if (m[i] > 0)
        cnt++;
        if (w[i] > k)
        cnt += ((w[i] - 1) / k) + 1;
        else if (w[i] > 0)
        cnt++;
        i++;   
    }
    cout << cnt;
}