#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[5];
    int i;
    int j;
    int sum;
    int tmp;

    i = 0;
    sum = 0;
    while (i < 5)
        cin >> arr[i++];
    i = 0;
    while (i < 5)
    {
        j = i + 1;
        while (j < 5)
        {
            if (arr[i] >= arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j++;
        }
        i++;
    }
    i = 0;
    while (i < 5)
        sum += arr[i++];
    cout << sum / 5 << '\n';
    cout << arr[2];
}
    