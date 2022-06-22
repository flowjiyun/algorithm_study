//두 배열 합치기
#include <iostream>

using namespace std;
int a[1000000];
int b[1000000];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int i = 0;
    int j = 0;
    while (i < n || j < m) // 배열의 원소값 비교 종료 조건
    {
        if ((i < n && j < m) && a[i] < b[j])  // 포인터가 배열을 벗어나지 않았을 때 비교
        {
            cout << a[i] << ' ';
            i++;
        }
        else if((i < n && j < m) && a[i] > b[j]) // 포인터가 배열을 벗어나지 않았을 때 비교
        {
            cout << b[j] << ' ';
            j++;
        }
        else if (i >= n) // 포인터가 배열을 벗어나면 남은 배열 원소 출력
        {
            cout << b[j] << ' ';
            j++;
        }
        else 
        {
            cout << a[i] << ' ';
            i++;
        }
    }
    return (0);
}