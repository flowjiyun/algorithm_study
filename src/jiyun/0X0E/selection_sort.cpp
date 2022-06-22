// selection sort implement
// 최소 값을 앞에서 부터 정렬
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[5] = {3, 2, 7, 4, 9};
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        int mindx = n - 1;
        for (int j = i; j < n; j++)
        {
            if (arr[mindx] < arr[j])
                mindx = j;
        }
        swap(arr[mindx], arr[i]);
    }
    for (auto i : arr)
        cout << i << ' '; 
    return (0);
}