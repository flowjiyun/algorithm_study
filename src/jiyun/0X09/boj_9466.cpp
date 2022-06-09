#include <iostream>

using namespace std;

int arr[100001];

int start[100001];
// hint : 시작점 가지고 다니면서  cycle 돌기. 순환했으면 팀이므로 다시 한바퀴 돌면서 -1로 업데이트
void doSearch(int i)
{
    int cur_i = i;
    while (1)
    {
        start[cur_i] = i;
        cur_i = arr[cur_i]; // 다음 인데스로 업데이트
        if (start[cur_i] == i) // 조가 짜여 졌는지 (시작점과 다시 연결이 됬는지)
        {
            while (start[cur_i] != -1) // 순환 되는 지점들 다시 돌면서 -1로 업데이트
            {
                start[cur_i] = -1;
                cur_i = arr[cur_i];
            }
            return;
        }
        else if (start[cur_i] != 0) // 전에 다른 시작점에서 탐색이 되었음.
            return;
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < 100001; i++)
        {
            start[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            if (start[i] == 0)
                doSearch(i); 
        }
        /*for (int i = 1; i <= n; i++)
        {
            cout << start[i] << ' ';
        }
        cout << '\n';*/
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (start[i] != -1)
                cnt++;
        }
        cout << cnt << '\n';
    }
    return (0);
}