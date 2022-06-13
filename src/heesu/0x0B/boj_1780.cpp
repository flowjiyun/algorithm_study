#include <iostream>
using namespace std;

int paper[2190][2190];
int n;
int Minus, zero, one;

void recur(int x, int y, int size)
{
	bool m, z, o;
	m = z = o = true;
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (paper[i][j] == -1)
			{
				z = false;
				o = false;
			}
			if (paper[i][j] == 0 )
			{
				m = false;
				o = false;
			}
			if (paper[i][j] == 1)
			{
				m = false;
				z = false;
			}
		}
	}
	if (m)
	{
		Minus++;
		return;
	}
	if (z)
	{
		zero++;
		return;
	}
	if (o)
	{
		one++;
		return;
	}
	
	recur(x, y, size/3);
	recur(x, y+size/3, size/3);
	recur(x+size/3, y, size/3);
	recur(x+size/3, y+size/3, size/3);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	recur(0, 0, n);
	cout << Minus << '\n';
	cout << zero << '\n';
	cout << one << '\n';
}
