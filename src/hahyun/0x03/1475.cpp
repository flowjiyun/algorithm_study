#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, result = 0, arr[10] = {};
    cin >> N;

    while (N > 0)
    {
        arr[N % 10] += 1;
        N /= 10;
    }
    for (int i = 0; i < 10; i++)
    {
        if (i == 6 || i == 9)
            continue;
        result = max(result, arr[i]);
    }
    result = max(result, (arr[6] + arr[9] + 1) / 2);
    cout << result;
}