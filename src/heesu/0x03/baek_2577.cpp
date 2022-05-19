#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	int result;
	int num[10] = {};
	int i;

	cin >> a >> b >> c;
	result = a * b * c;
	while (result)
	{
		num[result % 10]++;
		result /= 10;
	}
	i = 0;
	while (i < 10)
	{
		cout << num[i]  << '\n';
		i++;
	}
}
