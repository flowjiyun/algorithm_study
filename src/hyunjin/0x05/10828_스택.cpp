#include <bits/stdc++.h>
using namespace std;

int main()
{
	stack<int> s;
	int n, num;
	string order;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> order;

		if (order == "push") {
			cin >> num;
            s.push(num);
		}
        else if (order == "pop"){
            if (s.empty()) cout << -1 << "\n";
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if (order == "size")
            cout << s.size() << "\n";
        else if (order == "empty")
            cout << s.empty() << "\n";
        else if (order == "top"){
            if (s.empty()) cout << -1 << "\n";
            else cout << s.top() << "\n";
        }
	}
}
