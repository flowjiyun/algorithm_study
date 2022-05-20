#include <iostream>

using namespace std;

int* MakeArray(int* a)
{
	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
	}
	return (a);
}

int CountSame(int* a)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		if (a[i] == 1)
			cnt++;
	}
	return (cnt);
}
void PrintValue(int same)
{
	if (same == 1)
		cout << 'C';
	else if (same == 2)
		cout << 'B';
	else if (same == 3)
		cout << 'A';
	else if (same == 4)
		cout << 'E';
	else
		cout << 'D';
	cout << '\n';
}
int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[4];
	int b[4];
	int c[4];
	int a_s;
	int b_s;
	int c_s;

	a_s = CountSame(MakeArray(a));
	b_s = CountSame(MakeArray(b));
	c_s = CountSame(MakeArray(c));
	
	PrintValue(a_s);
	PrintValue(b_s);
	PrintValue(c_s);
	return (0);
}