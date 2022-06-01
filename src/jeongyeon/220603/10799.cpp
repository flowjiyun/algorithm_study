#include <stack>
#include <iostream>
#include <string>
/*
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string wd;
	cin >> wd;
	stack<char> s;
	int ans = 0;
	for (int i = 0; i < wd.length(); i++) {
		if (wd[i] == '(')
			s.push(wd[i]);
		else {
			if (wd[i - 1] == '(') {
				s.pop();
				ans += s.size();
			}
			else {
				s.pop();
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
*/