#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int i = 1;
	stack<int> s;
	string op;

	cin >> n;
	while (n--)
	{
		int num;
		cin >> num;
		if (num >= i)
		{
			while (num >= i)
			{
				s.push(i++);
				op += "+\n";
			}
			s.pop();
			op += "-\n";
		}
		else
		{
			if (!s.empty() && s.top() == num)
			{
				s.pop();
				op += "-\n";
			}
			else
			{
				cout << "NO" << '\n';
				return (0);
			}
		}
	}
	cout << op;
}
