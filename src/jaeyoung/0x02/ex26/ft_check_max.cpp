#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[9];
    int cnt;
    int max;
    int i;

    i = 0;
    max = 0;
    cnt = 0;
    while (i < 9)
    {
        cin >> arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
            cnt = i + 1;
        }
        i++;
    }
    cout << max <<'\n';
    cout << cnt;
}