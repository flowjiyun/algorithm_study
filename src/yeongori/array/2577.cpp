#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n1, n2, n3, res;
    int arr[10] = {};
    cin >> n1 >> n2 >> n3;
    res = n1 * n2 * n3;

    while (res > 0)
    {
        arr[res % 10]++;
        res /= 10;
    }

    for (int i: arr)
        cout << i << '\n';

    return (0);
}