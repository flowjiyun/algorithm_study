#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	int i = 1;
	queue<int> q;

	cin >> n;
	while (i <= n)
		q.push(i++);
	while (q.size() != 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
}
