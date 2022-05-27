#include <iostream>
#include <stack>
#include <string>
/*
using namespace std;

int main() {
	stack<int> sum;
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (sum.empty())
				cout << -1 << "\n";
			else
				sum.pop();
		}
		else 
			sum.push(x);
	}
	int m = sum.size();
	int ans = 0;
	while (m--) {
		ans += sum.top();
		sum.pop();
	}
	cout << ans;
	return 0;
}
*/