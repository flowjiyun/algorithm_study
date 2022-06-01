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
	int ans = 0,temp =1;
	for (int i = 0; i < wd.length(); i++) {
		if (wd[i] == '(') {
			temp *= 2;
			s.push(wd[i]);
		}
		else if(wd[i] == '[') {
			temp *= 3;
			s.push(wd[i]);
		}
		else if(wd[i] == ')') {
			if (s.empty() || s.top() != '(') {
				ans = 0;
				break;
			}
			if (wd[i - 1] == '(') {
				ans += temp;
				temp /= 2;
				s.pop();
			}
			else {
				temp /= 2;
				s.pop();
			}
		}
		else if(wd[i] == ']') {
			if (s.empty() || s.top() != '[') {
				ans = 0;
				break;
			}
			if (wd[i - 1] == '[') {
				ans += temp;
				temp /= 3;
				s.pop();
			}
			else {
				temp /= 3;
				s.pop();
			}
		}
	}
	if (s.size())
		cout << "0";
	else
		cout << ans;
	return 0;
}
*/