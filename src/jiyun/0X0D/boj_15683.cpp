#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define X first
#define Y second
int n, m;
int map[8][8]; // 감시 공간
int vis[8][8]; // cctv가 볼수 있는 위치 표시할 공간
vector<pair<int, int>> cam; // 카메라 위치 담을 벡터
int dx[4] = {1, 0, -1, 0}; // cctv 바라보는 방향
int dy[4] = {0, 1, 0, -1}; // 남 , 동, 북, 서 (반시계 방향으로 회전)

// cctv가 바라보는 방향 업데이트
void update(int x, int y, int dir)
{
    dir %= 4;
    while (true)
    {
        x += dx[dir]; // 바라보는 방향 좌표 늘려가기
        y += dy[dir];
        if (x < 0 || x >= n || y < 0 || y >= m) // 감시 구역을 넘어서면 update 종료
            return;
        if (vis[x][y] == 6) // 벽을 만나면 update 종료
            return;
        if (vis[x][y] != 0) // 다른 감시카메라 or 이미 감시가능한 구역이면 다음으로 
            continue;
        vis[x][y] = -1; // 모든 경우가 아닐 경우 -1 로 업데이트
    }
}

int solution()
{
    int mn = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0) // 사각지대 최대값 찾기
                mn++;
        }
    }
    for (int temp = 0; temp < static_cast<int>(pow(4, cam.size())); temp++) // 각 카메라당 4가지 방향으로 볼수 있고 모든 경우의 수는 4^k개
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vis[i][j] = map[i][j];
            }
        }
        int view = temp; // 현 시점 여러대의 카메라가 바라 볼수 있는 경우의 수(ex)10진수 15 4진법으로 032
        for (int i = 0; i < cam.size(); i++)
        {
            int dir = view % 4; // 첫 카메라의 초기 방향 (ex) 032 % 4 --> 2
            view = view /4; // 다음 카메라 방향 구하기 위해 업데이트 2--> 3--> 0 순으로 진행 될 것임
            int x = cam[i].X;
            int y = cam[i].Y;
            if (map[x][y] == 1)
            {
                update(x, y, dir);
            }
            else if (map[x][y] == 2)
            {
                update(x, y, dir);
                update(x, y, dir + 2);
            }
            else if (map[x][y] == 3)
            {
                update(x, y, dir);
                update(x, y, dir + 1);
            }
            else if (map[x][y] == 4)
            {
                update(x, y, dir);
                update(x, y, dir + 1);
                update(x, y, dir + 2);
            }
            else if (map[x][y] == 5)
            {
                update(x, y, dir);
                update(x, y, dir + 1);
                update(x, y, dir + 2);
                update(x, y, dir + 3);
            }
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (vis[i][j] == 0)
                        ans++;
                }
            }
            if (mn > ans)
                mn = ans;
        }     
    }
    return mn;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] != 0 && map[i][j] != 6)
                cam.push_back({i, j});
        }
    }
    int result = solution();
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vis[i][j] << ' ';
        }
        cout << '\n';
    }*/
    cout << result;
    return (0);
}