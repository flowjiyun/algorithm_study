#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
vector<pair<int, string>> v;

bool cmp(pair<int, string> i, pair<int, string> j)
{
    return i.first < j.first;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int k;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> k >> str;
        v.push_back({k, str});
    }

    stable_sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++)
        cout << v[i].first << " " << v[i].second << "\n";

    return 0;
}
