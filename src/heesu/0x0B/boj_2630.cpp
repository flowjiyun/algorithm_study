#include <iostream>
using namespace std;

int paper[128][128];
int n;
int blue, white;

void recur(int x, int y, int size)
{
	bool zero, one;
	zero = one = true;
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (paper[i][j] == 1)
				zero = false;
			if (paper[i][j] == 0)
				one = false;
		}
	}
	if (zero)
	{
		white++;
		return;
	}
	if (one)
	{
		blue++;
		return;
	}

	recur(x, y, size/2); // 왼쪽 위의 기준점
	recur(x, y+size/2, size/2); // 오른쪽 위의 기준점
	recur(x+size/2, y, size/2); // 왼쪽 아래의 기준점
	recur(x+size/2, y+size/2, size/2); // 오른쪽 아래의 기준점 
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
	cout << white << '\n';
	cout << blue << '\n';
}
