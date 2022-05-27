#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int i = 1;
	stack<pair<int, int>> s; //STL에서 쌍으로 표현되는 자료형을 위해 제공되는 컨테이너 

	cin >> n;
	while (i <= n)
	{
		int tower;
		cin >> tower;
		while (!s.empty())
		{
			if (tower < s.top().second)
			{
				cout << s.top().first << ' ';
				break;
			}
			s.pop();
		}

		if (s.empty())
		{
			cout << 0 << " ";
		}
		s.push(make_pair(i, tower)); //pair를 할당하는 방법 
		i++;
	}
}
