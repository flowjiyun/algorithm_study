#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

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

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
        cout << v[i] << "\n";

    return 0;
}
