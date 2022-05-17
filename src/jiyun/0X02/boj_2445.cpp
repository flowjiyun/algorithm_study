#include <iostream>

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int nb;
	cin >> nb;
	for (int i = 0; i < nb - 1; i++)
	{
		for (int j = 0; j < i + 1; j++)
			cout << '*';
		for (int j = 0; j < 2 * (nb - 1 - i); j++)
			cout << ' ';
		for (int j = 0; j < i + 1; j++)
			cout << '*';
		cout << '\n';
	}
	for (int i = 0; i < 2 * nb; i++)
		cout << '*';
	cout << '\n';
	for (int i = 0; i < nb - 1; i++)
	{
		for (int j = 0; j < nb - i - 1; j++)
			cout << '*';
		for (int j = 0; j < 2 * (i + 1); j++)
			cout << ' ';
		for (int j = 0; j < nb - i - 1; j++)
			cout << '*';
		cout << '\n';
	}
	return (0);
}