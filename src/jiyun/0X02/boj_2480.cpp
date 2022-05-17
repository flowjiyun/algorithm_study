#include <iostream>

using namespace std;
int CountMax(int* a)
{
	int max = 0;
	for (int i = 0; i < 3; i++)
	{
		if (max < a[i])
			max = a[i];
	}
	return (max);
}
int CountSame(int* a, int* same)
{
	int cnt = 1;
	for (int i = 0; i < 2; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			if (a[i] == a[j])
			{
				*same = a[i];
				cnt++;
			}
		}
	}
	return (cnt);
}

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a[3];
	int same = 0;
	int max;
	int cnt;
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
	}
	cnt = CountSame(a, &same);
	max = CountMax(a);
	if (cnt >= 3)
		cout << (10000 + same * 1000);
	else if (cnt == 2)
		cout << (1000 + same * 100);
	else
		cout << (max * 100);
	return (0);
}