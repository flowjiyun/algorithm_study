#include <iostream>
// 입력 값의 범위가 제한되어 있고 오름차순 출력이므로
// 해당 값이 몇 번 들어오는지 배열에 저장하고 
// 마지막에 탐색하면서 배열의 값만큼 반복하여 인덱스 출력
using namespace std;
int arr[10001];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr[val]++;
    }
    for (int i = 0; i < 10001; i++)
    {
        if (arr[i] != 0)
        {
            for (int j = 0; j < arr[i]; j++)
                cout << i << '\n';
        }
    }
    return (0);
}