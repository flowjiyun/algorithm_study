#include <iostream>
using namespace std;

int arr1[26];
int arr2[26];

int ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2;
	int i;
	int cnt;

	cin >> s1 >> s2;
	for (auto c : s1)
		arr1[c - 'a']++;
	for (auto c : s2)
		arr2[c - 'a']++;

	i = 0;
	cnt = 0;
	while (i < 26)
	{
		if (arr1[i] != arr2[i])
			cnt += ft_abs(arr1[i] - arr2[i]);
		i++;
	}
	cout << cnt << '\n';
}
