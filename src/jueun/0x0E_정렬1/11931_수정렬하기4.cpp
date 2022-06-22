#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

bool cmp(int i, int j)
{
    return i > j;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int k;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        v.push_back(k);
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++)
        cout << v[i] << "\n";

    return 0;
}
