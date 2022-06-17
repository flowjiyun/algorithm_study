#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll recur_multi(ll a, ll b, ll c)
{
    if (b == 1)
        return (a % c);
    ll result = recur_multi(a, b / 2, c);
    result = result * result % c;

    if (b % 2 == 0)
        return (result);
    return (result * a % c);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;

    cin >> a >> b >> c;
    cout << recur_multi(a, b, c);

}