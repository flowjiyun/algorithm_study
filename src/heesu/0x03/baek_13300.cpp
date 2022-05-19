#include <iostream>
using namespace std;

int arr[2][6] = {};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	int s, y;
	int i, j;
	int room;

	cin >> n >> k;
	i = 0;
	while (i < n)
	{
		cin >> s >> y;
		arr[s][y]++;
		i++;
	}
	i = 0;
	room = 0;
	while (i < 2)
	{
		j = 1;
		while (j < 7)
		{
			room = room + arr[i][j] / k;
			if (arr[i][j] % k != 0)
				room++;
			j++;
		}
		i++;
	}
	cout << room;
}
