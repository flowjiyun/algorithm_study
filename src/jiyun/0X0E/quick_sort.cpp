// quick sort implement
// average : O(nlogn)
// worst : O(n^2)
#include <iostream>
#include <algorithm>

using namespace std;
int arr[1000000];
void quick_sort(int st, int en)
{
    if (en <= st + 1)
        return;
    int pivot = arr[st];
    int l = st + 1;
    int r = en - 1;
    while (true)
    {
        while (l <= r && arr[l] <= pivot)
            l++;
        while (l <= r && arr[r] > pivot)
            r--;
        if (l > r)
            break;
        swap(arr[l], arr[r]);
    }
    swap(arr[st], arr[r]);
    quick_sort(st, r);
    quick_sort(r + 1, en);
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quick_sort(0, n);
    for (int i = 0; i < n; i++) cout << arr[i] << '\n';
    return (0);
}