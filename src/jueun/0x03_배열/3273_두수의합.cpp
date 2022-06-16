#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, k, cnt;
    int start, end, sum;
    vector<int> v;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> k;
        v.push_back(k);
    }

    cin >> x;

    sort(v.begin(), v.end());

    cnt = 0;
    start = 0;
    end = n - 1;

    while (start < end)
    {
        sum = v[start] + v[end];

        if (sum > x)
            end--;
        else if (sum < x)
            start++;
        else
        {
            cnt++;
            start++;
            end--;
        }
    }

    cout << cnt;
    return 0;
}