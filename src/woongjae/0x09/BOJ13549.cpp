#include <bits/stdc++.h>
using namespace std;

const int LMT = 100001;
int board[LMT+2];
int sis, bro;
queue<int> Q;
void teleport(int num)
{
    int tmp = num;
    if (!tmp) return;
    while (tmp < LMT && !board[bro])
    {
        if (!board[tmp])
        {
            board[tmp] = board[num];
            Q.push(tmp);
            if (tmp == bro) return;
        }
        tmp <<= 1;
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> sis >> bro;
    board[sis] = 1;
    Q.push(sis);
    teleport(sis);
    while (!board[bro])
    {
        int v = Q.front(); Q.pop();
        vector<int> nvLst = { v + 1, v - 1 };
        for (int nv : nvLst)
        {
            if (nv < 0 || LMT <= nv)
                continue;
            if (board[nv])
                continue;
            board[nv] = board[v] + 1;
            Q.push(nv);
            teleport(nv);
        }
    }
    cout << board[bro]-1;
}