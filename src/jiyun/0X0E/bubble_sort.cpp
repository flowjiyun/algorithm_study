//bubble sort implement
#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[5] = {5, 1, 2, 6, 4};
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr [j + 1]);
        }
    }
    for (auto i : arr)
        cout << i << ' ';
    return (0);
}