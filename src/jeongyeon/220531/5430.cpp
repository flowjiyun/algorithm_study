#include <deque>
#include <string>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	deque<int> d;
	while (n--) {
		string c,arr;
		int num;
		cin >> c >> num >> arr;
		string temp = "";
		for (int i = 0; i < arr.length();i++) {
			if (isdigit(arr[i]))
				temp += arr[i];
			else {
				if (!temp.empty()) {
					d.push_back(stoi(temp));
					temp = "";
				}
			}
		}
		int rev = 0;
		int cnt_error = 1;
		for (int i = 0; i < c.length(); i++) {
			if (c[i] == 'R') {
				rev++;
			}
			else {
				if (d.empty()) {
					cout << "error" << "\n";
					cnt_error = 0;
					break;
				}
				if (rev % 2 == 0)
					d.pop_front();
				else {
					d.pop_back();
				}
			}
		}
		if (cnt_error) {
			cout << '[';
			if (rev % 2 == 1) {
				while (d.size()) {
					cout << d.back();
					d.pop_back();
					if(d.size())
						cout << ",";
				}
			}
			else {
				while (d.size()) {
					cout << d.front();
					d.pop_front();
					if(d.size())
						cout << ",";
				}
			}
			cout << "]" << "\n";
		}
	}
	return 0;
}