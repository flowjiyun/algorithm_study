#include <iostream>
#include <deque>
#include <string>
/*
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	deque<int> l;
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		if (str == "push_front") {
			int x;
			cin >> x;
			l.push_front(x);
		}
		else if (str == "push_back") {
			int x;
			cin >> x;
			l.push_back(x);
		}
		else if (str == "pop_front") {
			if (l.empty())
				cout << -1 << "\n";
			else {
				cout << l.front() << "\n";
				l.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (l.empty())
				cout << -1 << "\n";
			else {
				cout << l.back() << "\n";
				l.pop_back();
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