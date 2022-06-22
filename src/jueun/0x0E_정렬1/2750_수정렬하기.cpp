#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000001];

void quick_sort(int start, int end)
{
    if (start >= end)
        return;

    int pivot = arr[start];
    int left = start + 1;
    int right = end - 1;

    while (1)
    {
        while (left <= right && arr[left] <= pivot)
            left++;
        while (left <= right && arr[right] >= pivot)
            right--;
        if (left > right)
            break;
        swap(arr[left], arr[right]);
    }

    swap(arr[start], arr[right]);
    quick_sort(start, right);
    quick_sort(right + 1, end);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quick_sort(0, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n";
    return 0;
}
