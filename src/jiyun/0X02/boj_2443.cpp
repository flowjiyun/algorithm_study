#include <iostream>

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int nb;
	cin >> nb;
	for (int i = nb; i > 0; i--)
	{
		for (int j = 0; j < nb - i; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < 2 * i - 1; j++)
		{
			cout << '*';
		}
		cout << '\n';
	}
	return (0);
}