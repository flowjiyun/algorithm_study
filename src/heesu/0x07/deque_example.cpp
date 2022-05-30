#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dq;
	dq.push_front(10); // 10
	dq.push_back(50); // 10 50
	dq.push_front(24); // 24 10 50
	for (auto x : dq)
		cout << x << '\n';
	cout << dq.size() << '\n'; // 3

	if (dq.empty())
		cout << "dq is empty\n";
	else
		cout << "dq is not empty\n";

	dq.pop_front(); // 10 50
	dq.pop_back(); // 10
	cout << dq.back() << '\n'; // 10
	
	dq.push_back(72); // 10 72
	cout << dq.front() << '\n'; // 10
	dq.push_back(12); // 10 72 12

	dq[2] = 17; // 10 72 17
	dq.insert(dq.begin()+1, 33); // 10 33 72 17
	dq.insert(dq.begin()+4, 60); // 10 33 72 17 60
	for (auto x : dq)
		cout << x << ' ';
	cout << '\n';

	dq.erase(dq.begin()+3); // 10 33 72 60
	cout << dq[3] << '\n'; // 60
	dq.clear(); // dq의 모든 원소 제거 
}
