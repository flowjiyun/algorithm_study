#include <iostream>
#include <algorithm>
using namespace std;
int l, c;
char ipt[20];
char arr[20];

int is_valid() {
	int v = 0;
	int c = 0;
	for (int i = 0; i < l; i++) {
		int t = arr[i];
		if (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u') v++;
		else c++;
	}

	if (v != 0 && c >= 2) return(1);
	return(0);
}

void run(int lev, int start) {
	if (lev == l) {
		if (is_valid()) {
			for (int i = 0; i < l; i++)
				cout << arr[i];
			cout << "\n";
		}
		return;
	}

	for (int i = start; i < c; i++) {
		arr[lev] = ipt[i];
		run(lev + 1, i + 1);
	}
}

int main()
{
	cin >> l >> c;
	for (int i = 0; i < c; i++)
		cin >> ipt[i];
	sort(ipt, ipt + c);
	run(0, 0);
}
