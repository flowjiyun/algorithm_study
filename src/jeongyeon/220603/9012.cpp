#include <stack>
#include <iostream>
#include <string>
/*
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string line;
		cin >> line;
		stack<char> s;
		int error = 1;
		for (int i = 0; i < line.length(); i++) {
			if ((line[i] == '[') || (line[i] == '('))
				s.push(line[i]);
			else if (line[i] == ')') {
				if (s.size() && s.top() == '(')
					s.pop();
				else {
					error = 0;
					break;
				}
			}
			else if (line[i] == ']') {
				if (s.size() && s.top() == '[')
					s.pop();
				else {
					error = 0;
					break;
				}
			}
		}
		if (s.empty() && error)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
*/