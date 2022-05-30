#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, i, j;
	int temp;
	int cnt = 0;
	deque<int> dq;

	cin >> n >> m;
	for (i = 1; i <= n; i++)
		dq.push_back(i);

	while (m--)
	{
		int num;
		cin >> num;
		for (i = 0; i < dq.size(); i++)
		{
			if (dq[i] == num)
			{
				temp = i;
				break;
			}
		}
		if (temp <= dq.size() / 2)
		{
			for (j = 0; j < temp; j++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
			dq.pop_front();
		}
		else
		{
			for (j = 0; j < dq.size() - temp; j++)
			{
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
			dq.pop_front();
		}
	}
	cout << cnt;
}
