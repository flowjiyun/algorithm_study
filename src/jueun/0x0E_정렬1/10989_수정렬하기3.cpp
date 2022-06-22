#include <iostream>
using namespace std;

int n;
int arr[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int k;

    for (int i = 0; i < n; i++)
    {
        cin >> k;
        arr[k]++;
    }

    for (int i = 0; i < 10001; i++)
    {
        if (arr[i] > 0)
        {
            for (int j = 0; j < arr[i]; j++)
                cout << i << "\n";
        }
    }

    return 0;
}
