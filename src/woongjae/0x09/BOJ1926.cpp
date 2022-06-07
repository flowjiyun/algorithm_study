#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502];        //array which contain the input of the board
bool vis[502][502];         //array which shows visited or not
int n,m;                    
int dx[4] = {1,0,-1,0};     //use when up, down, left, right of the board
int dy[4] = {0,1,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];     //input the num of board
    }
    int mx = 0;                     //max size of the square on the board
    int num = 0;                    //whole number of the square on the board
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0 || vis[i][j])      //if the queue was visited or the number of board is 0, ignore the node.
                continue;
            num++;                                  //if it is valid, increase the num of the square
            queue<pair<int,int>> Q;                 //make the queue to put in the valid square.
            vis[i][j] = 1;                          //if visited, increase the value of visited site
            Q.push({i,j});                          //if it is valid, push the index of the board to the queue
            int area = 0;                           //declare the variable to compare the size of the square which is saved in the previous size of square.
            while (!Q.empty())                      //if the square is valid.
            {
                area++;                             //increase the size of square to find.
                pair<int,int> cur = Q.front(); Q.pop();     //save the front of the queue to cur and pop it
                for (int dir = 0; dir < 4; dir++)           
                { 
                    int nx = cur.X + dx[dir];              //increase the value of dx to find up, down, left, right value of square on the board.
                    int ny = cur.Y + dy[dir]; 
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)     //check if it is valid range of the current point.
                        continue; 
                    if (vis[nx][ny] || board[nx][ny] != 1)          //check the validity of square
                        continue; 
                    vis[nx][ny] = 1;                                //increase the value of the visited point to not check next time.
                    Q.push({nx,ny});                                //push the current site to not finish the for statement
                }
            }
            mx = max(mx, area);                                     //compare the previous size of square and current size of square.
        }
    }
    cout << num << '\n' << mx;
}