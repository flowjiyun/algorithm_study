#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t; //테스트 케이스 개수 
	while (t--)
	{
		int n;
		string p, x;
		string temp = "";
		deque<int> dq;

		cin >> p; //수행할 함수 
		cin >> n; //배열 정수 개수 
		cin >> x; //배열 정수 
		
		for (int i = 0; i < x.length(); i++)
		{
			if (x[i] == '[')
				continue;
			else if (x[i] >= '0' && x[i] <= '9')
				temp += x[i];
			else if (x[i] == ',' || x[i] == ']')
			{
				if (!temp.empty())
				{
					dq.push_back(stoi(temp));
					temp.clear();
				}
			}
		}

		bool reverse = false;
		bool error = false;
		for (auto c : p)
		{
			if (c == 'R')
			{
				reverse = !reverse;
			}
			else if (c == 'D')
			{
				if (dq.empty())
				{
					error = true;
					break;
				}
				else
				{
					if (!reverse)
						dq.pop_front();
					else
						dq.pop_back();
				}
			}
		}

		if (error)
			cout << "error" << '\n';
		else
		{
			cout << "[";
			while (!dq.empty())
			{
				if (!reverse)
				{
					cout << dq.front();
					if (dq.size() > 1)
						cout << ',';
					dq.pop_front();
				}
				else
				{
					cout << dq.back();
					if (dq.size() > 1)
						cout << ',';
					dq.pop_back();
				}
			}
			cout << "]\n";
		}
	}
}
