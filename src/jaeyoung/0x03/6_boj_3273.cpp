#include <bits/stdc++.h>
using namespace std;

    int num[100000];
    int arr[2000000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i;
    int n;
    int x;
//  int num[100000];
//  int arr[2000000];
    int cnt;

    cnt = 0;
    cin >> n;
    i = 0;
    while (i < n)
        cin >> num[i++];
    cin >> x;
    i = 0;
    while (i < 2000000)
        arr[i++] = 0;
    i = 0;
    while (i < n)
    {
        if (x > num[i] && arr[(x - num[i])])
            cnt++;
        arr[num[i]] = 1;
        i++;
    }
    cout << cnt;
}