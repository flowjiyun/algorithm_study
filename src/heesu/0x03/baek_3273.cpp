#include <iostream>
using namespace std;

int arr[1000000] = {};
int num[1000000] = {};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	int i;
	int cnt;
	
	cin >> n;
	i = 0;
	while (i < n)
	{
		cin >> arr[i];
		i++;
	}

	cin >> x;

	i = 0;
	cnt = 0;
	while (i < n)
	{
		if (x - arr[i] > 0)
		{
			if (num[x - arr[i]] == 1)
				cnt++;
			num[arr[i]] = 1;
		}
		i++;
	}
	cout << cnt;
}
