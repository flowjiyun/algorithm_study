#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[3] = {};
    int result[10] = {};
    int mod;

    cin >> arr[0] >> arr[1] >> arr[2];
    mod = arr[0] * arr[1] * arr[2];
    while (mod > 0)
    {
        result[mod % 10] += 1;
        mod /= 10;
    }
    for (int i = 0; i < 10; i++)
        cout << result[i] << '\n';
}