#include <iostream>
#include <algorithm>
/*
using namespace std;

int n, m,x;
int arr[10], ans[10];
bool check[10];

void fun(int x) {
	if (x == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	int temp = 0;
	for (int i = 1; i <= n; i++) {
		if (!check[i]&&arr[i-1]!=temp) {
			ans[x] = arr[i-1];
			temp = ans[x];
			check[i] = 1;
			fun(x + 1);
			check[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr+n);
	//arr[0] = temp[0];
	//for (int i = 1; i < n; i++) {
	//	if (temp[i] != arr[t-1]) arr[t++] = temp[i];
	//}
	
	fun(0);
}
*/
