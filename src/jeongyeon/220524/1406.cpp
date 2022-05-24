#include <iostream>
#include <string>
#include <list>
/*
using namespace std;

int main() {
	int i;
	string str;
	cin >> str;
	cin >> i;
	list<char> l;
	for (auto a : str)
		l.push_back(a);
	// list<char>::iterator cursor = l.end(); ¿Í µ¿ÀÏ
	auto cursor = l.end();
	while (i--) {
		char wd;
		cin >> wd;
		if (wd == 'L') {
			if (cursor != l.begin()) {
				cursor--;
			}
		}
		else if (wd == 'D') {
			if (cursor != l.end()) {
				cursor++;
			}
		}
		else if (wd == 'B') {
			if (cursor != l.begin()) {
				cursor = l.erase(--cursor);
			}
		}
		else if (wd == 'P') {
			char j;
			cin >> j;
			l.insert(cursor, j);
		}
	}
	for (auto a : l)
		cout << a;
}
*/