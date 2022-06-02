#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		string s;
		stack<char> st;
		bool correct = true;

		getline(cin, s);
		if (s == ".")
			break;
		for (auto c : s)
		{
			if (c == '(' || c == '[')
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
			else if (c == ']')
			{
				if (st.empty() || st.top() != '[')
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
			cout << "yes\n";
		else
			cout << "no\n";
	}
}
