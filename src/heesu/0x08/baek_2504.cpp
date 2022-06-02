#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int sum = 0;
	int num = 1;
	stack<char> st;

	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			num *= 2;
			st.push(s[i]);
		}
		else if (s[i] == '[')
		{
			num *= 3;
			st.push(s[i]);
		}
		else if (s[i] == ')')
		{
			if (st.empty() || st.top() != '(')
			{
				cout << 0;
				break;
			}
			if (s[i - 1] == '(')
				sum += num;
			st.pop();
			num = num / 2;
		}
		else if (s[i] == ']')
		{
			if (st.empty() || st.top() != '[')
			{
				cout << 0;
				break;
			}
			if (s[i - 1] == '[')
				sum += num;
			st.pop();
			num = num / 3;
		}
	}
	if (!st.empty())
		cout << 0;
	cout << sum;
}
