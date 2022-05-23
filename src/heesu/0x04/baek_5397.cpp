#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int i;
	string s;

	cin >> n;
	for (i = 0; i < n; i++)
	{
		list<char> l = {};

		cin >> s;
		
		auto cursor = l.begin();
	
		for (auto c : s)
		{
			if (c == '-')
			{
				if (cursor != l.begin())
				{	
					cursor--;
					cursor = l.erase(cursor);
				}
			}
			else if (c == '<')
			{
				if (cursor != l.begin())
					cursor--;
			}
			else if (c == '>')
			{
				if (cursor != l.end())
					cursor++;
			}
			else
				l.insert(cursor, c);

		}
		for (auto c : l)
			cout << c;
		cout << '\n';
	}
}
