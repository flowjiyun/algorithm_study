#include <iostream>

using namespace std;
void ReverseSort(int* card, int a, int b)
{
	int i = a - 1;
	int j = b - 1;
	while (i < j)
	{
		int temp = card[i];
		card[i] = card[j];
		card[j] = temp;
		i++;
		j--;
	}
}
int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a;
	int b;
	int card[20];
	for (int i = 0; i < 20; i++)
	{
		card[i] = i + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		cin >> a >> b;
		ReverseSort(card, a, b);
	}
	for (int i = 0; i < 20; i++)
	{
		cout << card[i] << ' ';
	}
	return (0);
}