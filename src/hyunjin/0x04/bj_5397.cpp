#include <iostream>
using namespace std;
string str;
char dat[10000000];
int pre[10000000];
int nxt[10000000];
int cursor, unused;

void insert(int addr, char ch) {
	dat[unused] = ch;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];

	if (nxt[addr] != -1) pre[nxt[addr]] = unused;
	nxt[addr] = unused;
	unused++;
}

void erase(int addr) {
	if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
	nxt[pre[addr]] = nxt[addr];
}

int isword(char a) {
	if ('0' <= a && a <= '9')
		return (1);
	if ('a' <= a && a <= 'z')
		return (1);
	if ('A' <= a && a <= 'Z')
		return (1);
	return (0);
}

void run()
{
	for (auto c : str) {
		if (c == '<' && cursor)
			cursor = pre[cursor];
		else if (c == '>' && nxt[cursor] != -1)
			cursor = nxt[cursor];
		else if (c == '-' && cursor)
		{
			erase(cursor);
			cursor = pre[cursor];
		}
		else if (isword(c) == 1)
		{
			insert(cursor, c);
			cursor = nxt[cursor];
		}
	}

	int i = nxt[0];
	while (i != -1) {
		cout << dat[i];
		i = nxt[i];
	}
	cout << "\n";
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		fill(pre, pre + 10000000, -1);
		fill(nxt, nxt + 10000000, -1);		
		cursor = 0;
		unused = 1;

		cin >> str;
		run();
	}
}
