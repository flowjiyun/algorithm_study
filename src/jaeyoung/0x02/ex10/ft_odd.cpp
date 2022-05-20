#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[7];
    int i;
    int sum;
    int min;

    i = 0;
    sum = 0;
    min = 100;
    while (i < 7)
    {
        cin >> arr[i];
         i++;
    }
    i = 0;
    while (i < 7)
    {
        if (arr[i] % 2 == 1)
        {
            sum += arr[i];
            if (arr[i] < min)
                min = arr[i];
        }
        i++;
    }
    if (sum == 0)
    {
        cout << "-1";
        return (0);
    }
    cout << sum << '\n';
    cout << min;
}