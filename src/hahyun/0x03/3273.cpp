#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, count = 0, arr[1000000] = {}, result[2000000] = {};
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        if (x - arr[i] > 0 && result[x - arr[i]])
            count++;
        result[arr[i]] = 1;
    }
    cout << count;
}