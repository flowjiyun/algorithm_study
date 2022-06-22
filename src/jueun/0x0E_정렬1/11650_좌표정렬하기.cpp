#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int k, j;
    for (int i = 0; i < n; i++)
    {
        cin >> k >> j;
        v.push_back({k, j});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
        cout << v[i].first << " " << v[i].second << "\n";

    return 0;
}
