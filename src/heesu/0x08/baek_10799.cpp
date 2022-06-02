#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	stack<char> st;
	int result = 0;

	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			st.push(s[i]);
		else if (s[i] == ')')
		{
			if (s[i - 1] == '(')
			{
				st.pop();
				result += st.size();
			}
			else
			{
				st.pop();
				result++;
			}
		}
	}
	cout << result;
}
