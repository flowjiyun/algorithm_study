#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	deque<int> l;
	int n,m,left, right;
	int ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		l.push_back(i);
	}
	while (m--) {
		int num;
		cin >> num;

		for (int i = 0; i<l.size(); i++) {
			if (l[i] == num) {
				left = i;
				right = l.size() - i;
				break;
			}
		}
		if (left <= right) {
			while (true) {
				if (l.front() == num)
					break;
				l.push_back(l.front());
				l.pop_front();
				ans++;
			}
			l.pop_front();
		}
		else {
			
			while (true) {
				if (l.back() == num)
					break;
				l.push_front(l.back());
				l.pop_back();
				ans++;
			}
			l.pop_back();
		}
	}
	cout << ans;
	return 0;
}