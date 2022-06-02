#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, cnt = 0;

	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		stack<int> st;
		
		for (auto c : s)
		{
			if (!st.empty() && st.top() == c)
				st.pop();
			else
				st.push(c);
		}
		if (st.empty())
			cnt++;
	}
	cout << cnt << '\n';
}
