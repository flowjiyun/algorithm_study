#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	int i;
	list<int> l;

	cin >> n >> k;

	for (i = 1; i <= n; i++)
		l.push_back(i);
	auto cursor = l.begin();

	cout << '<';

	while (l.size() > 1)
	{
		for (i = 1; i < k; i++)
		{
			cursor++;
			if (cursor == l.end())
				cursor = l.begin();
		}

		cout << *cursor << ", ";

		cursor = l.erase(cursor);
	
		if (cursor == l.end())
			cursor = l.begin();
	}

	cout << *cursor << '>';
}
