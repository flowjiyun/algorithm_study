#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	stack<int> s;
	s.push(10); // 10
	s.push(20); // 10 20
	s.push(30); // 10 20 30
	cout << s.size() << '\n'; // 3

	if(s.empty())
		cout << "s is empty\n";
	else
		cout << "s is not empty\n";

	s.pop(); // 10 20
	cout << s.top() << '\n'; // 20
	s.pop(); // 10
	cout << s.top() << '\n'; // 10
	s.pop(); //empty

	if(s.empty())
		cout << "s is empty\n";
	cout << s.top() << '\n'; // runtime error 발생 
}
