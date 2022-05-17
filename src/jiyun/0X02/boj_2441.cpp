#include <iostream>

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int nb;
	cin >> nb;
	for (int i = 0; i < nb; i++)
	{
		for (int j = nb; j > 0; j--)
		{
			if (j > nb - i)
				cout << ' ';
			else
				cout << '*';
		}
		cout << '\n';
	}
	return (0);
}