#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[4];
    int i;
    int j;
    int tmp;

    i = 0;   
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    while (i < 4)
    {
        j = i + 1;
        while (j < 4)
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

    if (arr[0] != arr[1])
    {
        cout << "C";
        return (0);
    }
    if (arr[0] == 1)
        cout << "E";
    else if (arr[0] == arr[3])
        cout << "D";
    else if (arr[2] == 0)
        cout << "A";
    else if (arr[2] == 1)
        cout << "B";
}

