#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int ipt[10];
int arr[10];
int used[10];

void run(int lev) {
	if (lev == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
    
    int pre = -1;
	for (int i = 0; i < n; i++) {
		if (used[i] == 1) continue;
		if (ipt[i] == ipt[pre]) continue;

		used[i] = 1;
		arr[lev] = ipt[i];
		run(lev + 1);
		used[i] = 0;
		pre = i;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> ipt[i];
	sort(ipt, ipt + n);

	run(0);
}
