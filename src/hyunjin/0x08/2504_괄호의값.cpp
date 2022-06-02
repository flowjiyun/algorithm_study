#include <bits/stdc++.h>
using namespace std;

int run(string str) {
	deque<int> d;
	for (auto a : str) {
		if (a == '(' || a == '[') {
			if (a == '(') d.push_back(-2);
			else d.push_back(-3);
		}
		else {
			if (!d.empty() && d.back() < 0) {
				if ((a == ')' && d.back() == -3) || (a == ']' && d.back() == -2))
					return(0);
				d.back() *= -1;
			}
			else if (d.size() > 1 && d.back() > 0) {
				if ((a == ')' && *(d.end() - 2) == -3) || (a == ']' && *(d.end() - 2) == -2))
					return (0);
				*(d.end() - 2) *= -d.back();
				d.pop_back();
			}
			else return (0);

			if (d.size() > 1 && *(d.end() - 2) > 0) {
				*(d.end() - 2) += d.back();
				d.pop_back();
			}
		}
	}
	if (d.size() == 1 && d.back() > 0) return (d.back());
	else return (0);
}

int main()
{
	string str;
	cin >> str;

	cout << run(str);
}
