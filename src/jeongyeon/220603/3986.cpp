#include <stack>
#include <iostream>
#include <string>
/*
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	int n,ans=0;
	cin >> n;
	while (n--) {
		stack<char> s;
		string wd;
		cin >> wd;
		for (int i = 0; i < wd.length(); i++) {
			if (s.size()) {
				if (wd[i] == 'A') {
					if (s.top() == 'A') {
						s.pop();
					}
					else {
						s.push(wd[i]);
					}
				}
				else {
					if (s.top() == 'B') {
						s.pop();
					}
					else {
						s.push(wd[i]);
					}
				}
			}
			else {
				s.push(wd[i]);
			}
		}
		if (s.size()==0)
			ans++;
	}
	cout << ans;
	return 0;
}
*/