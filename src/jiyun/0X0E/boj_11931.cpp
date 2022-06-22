// 수 정렬 - 내림차순 - merge sort
// 1. 정렬할 데이터를 반으로 나누고 정렬하는 과정
// 2. 정렬된 나누어진 데이터를 다시 합치는 과정(merge)

#include <iostream>

using namespace std;
int arr[1000000];
int temp[1000000];
void merge(int st, int en)
{
    int mid = (st + en) / 2;
    int left = st;
    int right = mid;
    for (int i = st; i < en; i++)
    {
        if (left == mid)
            temp[i] = arr[right++];
        else if (right == en)
            temp[i] = arr[left++];
        else if (arr[left] >= arr[right])
            temp[i] = arr[left++];
        else
            temp[i] = arr[right++];
    }
    for (int i = st; i < en; i++) // 원래 input 값 갱신
        arr[i] = temp[i];
}

void merge_sort(int st, int en)
{
    if (en == st + 1) // 데이터가 1개가 될때까지 나눈다 1개일 때 정열할 필요없음
        return;
    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    merge_sort(0, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
    return (0);
}