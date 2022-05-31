#include <iostream>
#include <queue>
#include <string>
/*
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	queue<int> l;
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		if (str == "push") {
			int x;
			cin >> x;
			l.push(x);
		}
		else if (str == "pop") {
			if (l.empty())
				cout << -1 << "\n";
			else {
				cout << l.front() << "\n";
				l.pop();
			}
		}
		else if (str == "size") {
			cout << l.size() << "\n";
		}
		else if (str == "front") {
			if (l.empty())
				cout << -1 << "\n";
			else
				cout << l.front() << "\n";
		}
		else if (str == "back") {
			if (l.empty())
				cout << -1 << "\n";
			else
				cout << l.back() << "\n";
		}
		else {
			cout << l.empty() << "\n";
		}
	}
	return 0;
}
*/