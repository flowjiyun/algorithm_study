#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		stack<char> st;
		bool correct = true;

		for (auto c : s)
		{
			if (c == '(')
			{
				st.push(c);
			}
			else if (c == ')')
			{
				if (st.empty() || st.top() != '(')
				{
					correct = false;
					break;
				}
				st.pop();
			}
		}
		if (!st.empty())
			correct = false;
		if (correct)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
