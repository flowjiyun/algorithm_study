#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    vector<int> v(201);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> k;
        v[k + 100]++;
    }

    cin >> m;

    cout << v[m + 100];

    return 0;
}