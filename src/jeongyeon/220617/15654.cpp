#include <iostream>
#include <vector>
#include <algorithm>
/*
using namespace std;

int n, m,x;
int arr[10], ans[10];
bool check[10];
vector<int> v;

void fun(int x) {
	if (x == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			ans[x] = arr[i-1];
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
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		arr[i] = v[i];
	}
	fun(0);
}
*/
