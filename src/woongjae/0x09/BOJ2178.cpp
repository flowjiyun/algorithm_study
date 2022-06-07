#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[102];
int dist[102][102];                 //distance from the primal index. 
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int m;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    for(int i = 0; i < n; i++) 
        fill(dist[i], dist[i] + m, -1);     //fill the dist array with -1. initializing.
    queue<pair<int, int>> q;                //declare the queue to put the index of map
    q.push({0, 0});                         //push the primal index of map to the queue
    dist[0][0] = 0;                         //the distance from the primal index is zero.
    while(!q.empty())
    {
        auto cur = q.front();               //save the front of the que into the cursor.
        q.pop();                            //pop the queue.
        for (int dir = 0; dir < 4; dir++)
        {       
            int nx = cur.X + dx[dir];       //check the up, down, left, right side of the cursor
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)     //check the validity of the board. if it is out of range, ignore it.
                continue; 
            if (board[nx][ny] != '1' || dist[nx][ny] >= 0)  //if it is checked or not the range of the board, ignore it.
                continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;          // target point is the distance of the cursor from primal point, so if it is valid, increase the value of the dist array.
            q.push({nx,ny});                            // push the next valid index of array to the queue.
        }
    }
    cout << dist[n - 1][m - 1] + 1;             // the range size of the array is 1 shorter than real size, so increase 1 the value of it when print it.
}