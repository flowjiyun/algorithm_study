#include <iostream>

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a;
	cin >> a;
	if (a >= 90)
		cout << 'A';
	else if (a >= 80)
		cout << 'B';
	else if (a >= 70)
		cout << 'C';
	else if (a >= 60)
		cout << 'D';
	else
		cout << 'F';

	return (0);
}