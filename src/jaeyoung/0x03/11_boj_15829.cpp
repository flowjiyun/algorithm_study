#include <bits/stdc++.h>
using namespace std;

unsigned long long ft_expo(int n)
{
    int i;
    unsigned long long res;

    res = 1;
    if (n == 0)
        return (1);
    i = 0;
    while (i++ < n)
        res *= 31;
    return (res);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int i;
    unsigned long long j;
    unsigned long long sum;
    int num[26] = {};
    char    s;

    sum = 0;
    cin >> n;
    i = 0;
    for (auto &c : num)
        c = ++i;
    i = 0;
    while (i < n)
    {
        cin >> s;
        j = ft_expo(i);
        sum += num[s - 'a'] * j;
        i++;
    }
    cout << sum;
}