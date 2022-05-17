#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int x;

	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a < x)
		{
			cout << a << ' ';
		}
	}
	return (0);
}
