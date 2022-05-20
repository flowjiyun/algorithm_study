#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[3];
    int tmp;
    int i;
    int j;

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
    i = 0;
    while (i < 3)
    {
        cout << arr[i] << ' ';
        i++;
    }
}
