#include <iostream>
#include <queue>
/*
using namespace std;

int board[1000002];
int f,s,g,u,d;
bool check = 1;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> f >>s >>g >>u >>d;
	if (s == g) {
		cout << 0;
		return 0;
	}
	queue<int> q;
	board[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int move = q.front(); q.pop();
		if (move == g) {
			cout << board[move]-1;
			check = 0;
			break;
		}
		if (move - d > 0 && board[move - d] == 0) {
			q.push(move - d);
			board[move - d] = board[move] + 1;
		}
		if (move + u <= f && board[move + u] == 0) {
			q.push(move + u);
			board[move + u] = board[move] + 1;
		}
	}
	if(check == 1)
		cout << "use the stairs";
	return 0;
}
*/