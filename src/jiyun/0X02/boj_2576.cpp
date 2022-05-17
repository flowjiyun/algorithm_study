#include <iostream>

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int nb;
	int odd = 0;
	int min = 100;

	for (int i = 0; i < 7; i++)
	{
		cin >> nb;
		if (nb % 2 == 1)
		{
			if (nb < min)
			{
				min = nb;
			}
			odd += nb;
		}
	}
	if (odd)
	{
		cout << odd << '\n' << min;
	}
	else
		cout << -1;
	return (0);
}