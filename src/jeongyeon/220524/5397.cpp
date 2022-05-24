#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		list<char> l;
		// list<char>::iterator cursor = l.end(); ¿Í µ¿ÀÏ
		auto cursor = l.end();

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '-') {
				if (cursor == l.begin())
					continue;
				cursor = l.erase(--cursor);
			}
			else if (str[i] == '<') {
				if (cursor == l.begin())
					continue;
				cursor--;
			}
			else if (str[i] == '>') {
				if (cursor == l.end())
					continue;
				cursor++;
			}
			else {
				l.insert(cursor, str[i]);
			}
		}
		for (auto a : l)
			cout << a;
		cout << '\n';
	}
}