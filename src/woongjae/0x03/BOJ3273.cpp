#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int i;
    int x;
    int cnt;
    int j;

    cnt = 0;
    i = 0;
    cin >> n;
    int arr[n];
    while (i < n)
    {
        cin >> arr[i];
        i++;
    }
    i = 0;
    cin >> x;
    while (i < n - 1)
    {
        j = i + 1;
        while (j < n)
        {
            if(x == (arr[i] + arr[j]))
                cnt++;
            j++;
        }
        i++;
    }
    cout << cnt;
}