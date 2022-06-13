#include <iostream>
using namespace std;

void func(int a, int b, int n)
{
	if (n == 1)
	{
		cout << a << ' ' << b << '\n';
		return;
	}
	func(a, 6-a-b, n-1);
	cout << a << ' ' << b << '\n';
	func(6-a-b, b, n-1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;
	cout << (1<<k) - 1 << '\n'; // left shift 비트 연산자. 1을 비트 기준 왼쪽으로 k칸 밀으라는 의미 
	func(1, 3, k);
}
