#include <iostream>
#include <stack>
/*
using namespace std;

int main() {
	int index=0,n,max=0;
	cin >> n;
	stack<int> s;
	char ans[200001];

	while (n--) {
		int x;
		cin >> x;
		if (x > max) {
			for (int i = max + 1; i <= x; i++) {
				s.push(i);
				ans[index++] = '+';
			}
		}
		else 
			if (s.top() !=x) {
				cout << "NO";
				return 0;
			}
		s.pop();
		ans[index++] = '-';
		if (x > max)
			max = x;
	}
	for (int i = 0; i < index; i++)
		cout << ans[i] << "\n";
	return 0;
}
*/