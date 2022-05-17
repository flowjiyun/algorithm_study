#include <iostream>

using namespace std;

void SortUp(int* a)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a[5];
	int sum = 0;
	for (int i = 0; i < 5; i++)
		cin >> a[i];
	for (int i = 0; i < 5; i++)
		sum += a[i];
	cout << sum / 5 << '\n';
	SortUp(a);
	cout << a[2];
	return (0);
}