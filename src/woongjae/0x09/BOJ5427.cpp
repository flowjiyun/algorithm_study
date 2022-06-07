#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int TC, bX, bY;
int board[1002][1002];
int visF[1002][1002];
int visS[1002][1002];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    for (int testNo = 0; testNo < TC; testNo++)
    {
        bool escape = false;
        queue<pair<int, int>> Qf = {}, Qs = {};         // declare the queue inside the main function because the queue has to be initialized when the case is changed.
        cin >> bY >> bX;                                // resize the size of the board.
        for (int i = 0; i < bX; i++)
        {
            fill(visF[i], visF[i] + bY, 0);             // initialize the visit array of fire and the person who is inside the board.
            fill(visS[i], visS[i] + bY, 0);             
        }
        for (int i = 0; i < bX; i++)
            for (int j = 0; j < bY; j++)
            {
                char c;
                cin >> c;                               // put the input value to the board to char so check every value of the input value.
                if (c == '#')
                board[i][j] = -1;                       // if the character is '#' it means it is the wall. so initialize it as -1.
                else 
                {
                    if (c == '@')                       // it is primal point of the person. push it to the person queue.
                    {
                        Qs.push({i, j});
                        visS[i][j] = 1;
                    } 
                    else if (c == '*')                  // it means it is fire. push it to fire queue.
                    {
                        Qf.push({i, j});
                        visF[i][j] = 1;
                    }
                    board[i][j] = 0;
                }
            }
        while (!Qf.empty()) 
        {
            auto v = Qf.front();
            Qf.pop();
            for (int k = 0; k < 4; k++) 
            {
                int nx = v.X + dx[k];
                int ny = v.Y + dy[k];
                if (nx < 0 || bX <= nx || ny < 0 || bY <= ny) continue;
                if (board[nx][ny] == -1) continue;
                if (visF[nx][ny]) continue;
                visF[nx][ny] = visF[v.X][v.Y] + 1;
                Qf.push({nx, ny});
            }
        }
        while ((!Qs.empty()) && (!escape)) 
        {
            auto v = Qs.front();
            Qs.pop();
            for (int k = 0; k < 4; k++) 
            {
                int nx = v.X + dx[k];
                int ny = v.Y + dy[k];
                if (nx < 0 || bX <= nx || ny < 0 || bY <= ny) 
                {
                    cout << visS[v.X][v.Y] << '\n';
                    escape = true;
                    break;
                }
                if (board[nx][ny] == -1) 
                    continue;
                if (visS[nx][ny]) 
                    continue;
                if (visF[nx][ny] != 0 && visF[nx][ny] <= visS[v.X][v.Y] + 1) 
                    continue;
                visS[nx][ny] = visS[v.X][v.Y] + 1;
                Qs.push({nx, ny});
            }
        }
        if (!escape) 
        cout << "IMPOSSIBLE" << '\n';
    }
}