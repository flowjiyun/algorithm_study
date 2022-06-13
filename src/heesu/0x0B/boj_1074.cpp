#include <iostream>
using namespace std;

int func(int n, int r, int c)
{
	if (n == 0)
		return (0);
	if (r < half && c < half)
		return func(n-1, r, c);
	if (r < half && c >= half)
		return half*half + func(n-1, r, c-half);
	if (r >= half && c < half)
		return 2*half*half + func(n-1, r-half, c);
	return 3*half*half + func(n-1, r-half, c-half); // half : 한 변 길이의 절반, 즉 2^n-1
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);
}
