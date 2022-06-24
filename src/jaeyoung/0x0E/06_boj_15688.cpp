#include <iostream>
using namespace std;

int n, num;
int arr[2000005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr[num + 1000000]++;
    }
    for (int i = 0; i < 2000005; i++)
    {
        while (arr[i])
        {
            cout << i - 1000000 << '\n';
            arr[i]--;
        }
    }
}