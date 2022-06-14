#include <iostream>
using namespace std;
using ll = long long;

int run(ll a, ll b, ll m) {
	if (b == 1) return (a % m);

	ll val = run(a, b / 2, m);
	val = val * val % m;
	if (b % 2 == 0) return (val);
	else return (val * a % m);
}

int main()
{
	ll a, b, m;
	cin >> a >> b >> m;

	cout << run(a, b, m);
}
