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
		for (int j = 0; j < i + 1; j++)
		{
			cout << '*';
		}
		cout << '\n';
	}
	return (0);
}