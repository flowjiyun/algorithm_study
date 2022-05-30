#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	q.push(10); // 10
	q.push(20); // 10 20
	q.push(30); // 10 20 30
	cout << q.size() << '\n'; // 3

	if(q.empty())
		cout << "q is empty\n";
	else 
		cout << "q is not emptt\n";

	q.pop(); // 20 30
	cout << q.front() << '\n'; // 20
	cout << q.back() << '\n'; // 30

	q.push(40); // 20 30 40
	q.pop(); // 30 40
	cout << q.front() << '\n'; // 30
}
