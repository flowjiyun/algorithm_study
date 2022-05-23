#include <iostream>
using namespace std;
string str;
int cursor, unused;
int pre[1000005], nxt[1000005];
char dat[1000005];

void insert(int addr, char a)
{
	dat[unused] = a;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];

	if (nxt[addr] != -1) pre[nxt[addr]] = unused;
	nxt[addr] = unused;
	unused++;
}

void erase(int addr)
{
	nxt[pre[addr]] = nxt[addr];
	if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void run()
{
	char order;
	cin >> order;

	if (order == 'L' && cursor != 0)
		cursor = pre[cursor];
	else if (order == 'D' && nxt[cursor] != -1)
		cursor = nxt[cursor];
	else if (order == 'B' && cursor != 0) {
		erase(cursor);
		cursor = pre[cursor];
	}
	else if (order == 'P') {
		char a;
		cin >> a;
		insert(cursor, a);
		cursor = nxt[cursor];
	}
}

int main()
{
	int n;
	cin >> str >> n;
	cursor = 0;
	unused = 1;
	fill(pre, pre + 1000005, -1);
	fill(nxt, nxt + 1000005, -1);
	for (auto c : str) {
		insert(cursor, c);
		cursor++;
	}

	for (int i = 0; i < n; i++) {
		run();
	}
	
	int i = nxt[0];
	while (i != -1) {
		cout << dat[i];
		i = nxt[i];
	}
}
