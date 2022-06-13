#include <iostream>
using namespace std;

using ll = long long;

ll pow(lla, ll b, ll c)
{
	if (b == 1) // base condition
		return (a % c);
	ll val = pow(a, b/2, c);
	val = val * val % c;
	if (b % 2 == 0) // 짝수이면 바로 반환 
		return val;
	return val * a % c; // 홀수이면 a를 한번 더 곱함  
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a, b, c;
	cout << pow(a, b, c);
}
