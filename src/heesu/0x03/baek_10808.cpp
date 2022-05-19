#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt;
	string s;
	
	cin >> s;
	for (char a = 'a'; a <= 'z'; a++)
	{
		cnt = 0;
		for (auto c : s)
			if (a == c)
				cnt++;
		cout << cnt << ' ';
	}
}
