#include <iostream>

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		cout << a[i] << ' ';
	}
	return (0);
}