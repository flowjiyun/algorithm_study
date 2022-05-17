#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;

    int n, avg;

    avg = 0;

    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        v.push_back(n);
        avg += n;
    }

    sort(v.begin(), v.end());

    cout << avg / 5 << "\n";
    cout << v[2];

    return 0;
}