#include <iostream>
using namespace std;
int dat[10000000];
int pre[10000000] = { -1 };
int nxt[10000000] = { -1 };
int unused = 1;
int n, k;

void insert(int addr, int num) {
	dat[unused] = num;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];

	if (nxt[addr] != -1) pre[nxt[addr]] = unused;
	nxt[addr] = unused;
	unused++;
}

void erase(int addr) {
	nxt[pre[addr]] = nxt[addr];
	if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void run() {
	int tar = 0;
	cout << "<";
	for (int i = 0; i < n; i++) {
		for (int t = 0; t < k; t++) {
			tar = nxt[tar];
		}
		cout << dat[tar];
		erase(tar);
		if (i != n - 1) cout << ", ";
	}
	cout << ">";
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		insert(i - 1, i);
	pre[1] = n;
	nxt[n] = 1;

	run();
}
