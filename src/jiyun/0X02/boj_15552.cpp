#include <iostream>

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int nb;
	int a;
	int b;
	cin >> nb;
	for (int i = 0; i < nb; i++)
	{
		cin >> a >> b;
		cout << a + b << '\n';
	}
	return (0);
}