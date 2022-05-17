#include <iostream>

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int nb;
	int time;
	int sumM = 0;
	int sumY = 0;

	cin >> nb;
	for (int i = 0; i < nb; i++)
	{
		cin >> time;
		sumM += ((time / 60) + 1) * 15;
		sumY += ((time / 30) + 1) * 10;
	}
	if (sumM > sumY)
	{
		cout << "Y " << sumY;
	}
	else if (sumM < sumY)
	{
		cout << "M " << sumM;
	}
	else
		cout << "Y " << "M " << sumY;
	return (0);
}