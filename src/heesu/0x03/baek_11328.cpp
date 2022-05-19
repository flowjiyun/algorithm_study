#include <iostream>
using namespace std;

int arr1[26];
int arr2[26];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int i, j;
	string s1, s2;
	bool flag = true;

	cin >> n;

	while(n--)
	{
		cin >> s1 >> s2;

		for (auto c : s1)
			arr1[c - 'a']++;
		for (auto c : s2)
			arr2[c - 'a']++;
		flag = true;

		i = 0;
		while (i < 26)
		{
			if (arr1[i] != arr2[i])
			{
				flag = false;
				break;
			}
			i++;
		}

		i = 0;
		while (i < 26)
		{
			arr1[i] = 0;
			arr2[i] = 0;
			i++;
		}

		if (flag)
			cout << "Possible" << '\n';
		else
			cout << "Impossible" << '\n';
	}
}
