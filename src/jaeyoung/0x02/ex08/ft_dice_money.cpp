#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[3];
    int i;
    int j;
    int tmp;

    i = 0;
    cin >> arr[0] >> arr[1] >> arr[2];
    while (i < 3)
    {
        j = i + 1;
        while (j < 3)
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
        
    if (arr[0] == arr[1] && arr[1] == arr[2])
        cout << 10000 + arr[0] * 1000;
    else if (arr[0] == arr[1] || arr[1] == arr[2])
        cout << 1000 + arr[0] * 100;
    else
        cout << arr[2] * 100;
}