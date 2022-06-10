#include <iostream>
using namespace std;
int n;
int arr[1000005];
int state[1000005];

int not_visited = 0;
int visited = 1;
int cycle = 2;
int not_cycle = 3;

void run(int idx) {
	int cur = idx;
	for (int i = 0; i < n; i++) {
		state[cur] = visited;
		cur = arr[cur];

		// 1. 사이클을 처음 발견하면
		if (state[cur] == visited) {
			while (state[cur] != cycle) { // 사이클 안의 원소 전부 cycle찍기
				state[cur] = cycle;
				cur = arr[cur];
			}
			cur = idx;
			while (state[cur] != cycle) { // 사이클 밖의 원소 전부 not_cycle 찍기
				state[cur] = not_cycle;
				cur = arr[cur];
			}

			return;
		}

		// 2. 이전에 찍었던 사이클이나 not사이클을 만나면
		if (state[cur] == cycle || state[cur] == not_cycle) {
			cur = idx;
			while (state[cur] != cycle && state[cur] != not_cycle) { // 처음 받은 idx부터 바로 이전 원소까지 전부 not_cycle 찍기
				state[cur] = not_cycle;
				cur = arr[cur];
			}

			return;
		}
	}
}

int main()
{
	int test;
	cin >> test;
	while (test--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			state[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			if (state[i] == not_visited) run(i);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (state[i] == not_cycle) cnt++;
		}
		cout << cnt << "\n";
	}
}
