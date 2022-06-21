#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, startSum, linkSum;
int arr[21][21];
int visited[21], checked[21];

vector<int> startTeam, linkTeam;
int mmin = 1000000001;

int cal(vector<int> v, int idx, int cnt, int sum)
{
    if (cnt == 2)
        return sum;

    int tmp = 0;

    for (int i = idx; i < n / 2; i++)
    {
        int n1 = v[idx];
        int n2 = v[i];

        if (checked[n2] == 0)
        {
            checked[n2] = 1;
            tmp += cal(v, i, cnt + 1, arr[n1][n2] + arr[n2][n1]);
            checked[n2] = 0;
        }
    }

    return tmp;
}

void dfs(int idx, int cnt)
{
    if (cnt == n / 2)
    {
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
                linkTeam.push_back(i);
        }

        startSum += cal(startTeam, 0, 0, 0);
        for (int i = 0; i < n; i++)
            checked[i] = 0;
        linkSum += cal(linkTeam, 0, 0, 0);

        mmin = min(mmin, abs(startSum - linkSum));

        linkTeam.clear();
        startSum = 0;
        linkSum = 0;
        return;
    }

    for (int i = idx + 1; i < n; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            startTeam.push_back(i);
            dfs(i, cnt + 1);
            visited[i] = 0;
            startTeam.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    dfs(0, 0);

    cout << mmin;

    return 0;
}
