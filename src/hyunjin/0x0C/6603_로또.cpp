#include <iostream>
#include <algorithm>
using namespace std;
int k;
int ipt[50];
int arr[6];
int used[50];

void run(int lev, int start) {
	if (lev == 6) {
		for (int i = 0; i < 6; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = start; i < k; i++) {

		arr[lev] = ipt[i];
		run(lev + 1, i + 1);
	}
}

int main()
{
	while (1) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++)
			cin >> ipt[i];
		sort(ipt, ipt + k);

		run(0, 0);
		cout << "\n";
	}
}
