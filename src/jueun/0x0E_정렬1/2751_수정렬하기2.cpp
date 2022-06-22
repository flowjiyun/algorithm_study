#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000001];
int tmp[1000001];

void merge(int start, int end)
{
    int mid = (start + end) / 2;

    int i = start;
    int j = mid + 1;
    int k = start;

    while (i <= mid && j <= end)
    {
        if (arr[i] > arr[j])
        {
            tmp[k++] = arr[j++];
        }

        else
        {
            tmp[k++] = arr[i++];
        }
    }

    if (i > mid)
    {
        while (j <= end)
            tmp[k++] = arr[j++];
    }

    else
    {
        while (i <= mid)
            tmp[k++] = arr[i++];
    }

    for (int p = start; p <= end; p++)
        arr[p] = tmp[p];
}

void merge_sort(int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    merge(start, end);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    merge_sort(0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n";
    return 0;
}
