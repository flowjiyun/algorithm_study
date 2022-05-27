#include <iostream>
#include <stack>
/*
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	int n,max;
	cin >> n;
	stack<pair<int, int>> st;
	for (int i = 1; i <=n; i++) {
		cin >> max;
		while(!st.empty()) {
			if (max < st.top().first) {
				cout << st.top().second << " ";
				break;
			}
			st.pop();
		}
		if (st.empty())
			cout << 0 << " ";
		st.push({ max, i });
	}
	return 0;
}
*/