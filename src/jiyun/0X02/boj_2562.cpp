#include <iostream>

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int max = 0;
	int cnt = 0;
	int nb;
	for (int i = 0; i < 9; i++)
	{
		cin >> nb;
		if (max < nb)
		{
			max = nb;
			cnt = i + 1;
		}
	}
	cout << max << '\n' << cnt;
	return (0);
}