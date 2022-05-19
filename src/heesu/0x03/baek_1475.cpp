#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int i;
	int num[10] = {};
	int max;

	cin >> n;
	while (n)
	{
		num[n % 10]++;
		n /= 10;
	}
	num[6] = (num[6] + num[9] + 1) / 2;
	
	i = 0;
	max = 0;
	while (i < 9)
	{
		if (max < num[i])
			max = num[i];
		i++;
	}
	cout << max;
}
