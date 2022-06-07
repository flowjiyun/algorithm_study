#include <iostream>
#include <queue>
/*
using namespace std;

int board[100001];
int n, m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	queue<int> q;
	board[n] = 0;
	q.push(n);
	while (!q.empty()) {
		int move = q.front();
		q.pop();
		if (move == m) {
			cout << board[move];
			break;
		}
		if (move - 1 >= 0 && board[move-1] == 0) {
			q.push(move-1);
			board[move - 1] = board[move]+1;
		}
		if (move + 1 <= 100000 && board[move + 1] == 0) {
			q.push(move+1);
			board[move + 1] = board[move] + 1;
		}
		if (move * 2 <= 100000 && board[move *2] == 0) {
			q.push(move*2);
			board[move *2] = board[move] + 1;
		}
	}
}
*/