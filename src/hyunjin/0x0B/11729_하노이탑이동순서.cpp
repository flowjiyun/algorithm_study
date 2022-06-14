#include <iostream>
using namespace std;

void run(int a, int b, int n) {
	if (n == 1) {
		cout << a << " " << b << "\n";
		return;
	}
	run(a, 6 - a - b, n - 1);
	cout << a << " " << b << "\n";
	run(6 - a - b, b, n - 1);
}

int main()
{
	int n;
	cin >> n;

	// 하노이탑 옮기는 횟수 : 2^n - 1
	cout << (1 << n) - 1 << "\n"; // (비트연산자) 1<<n == 2^n
	run(1, 3, n);
}
