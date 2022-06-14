#include <iostream>
using namespace std;
using ll = long long;

ll pow(ll a, ll b, ll c)
{
    if (b == 1)
        return (a % c);
    ll val = pow(a, b / 2, c);
    val = val * val % c;
    if (b % 2 == 0)
        return (val);
    return (val * a % c);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;

    cout << pow(a, b, c);

}