// 종이의 갯수
// 1. k = 0 일 때 종이의 갯수를 구할 수 있음. 비교후 같으면 갯수 하나 증가
// -1 이면 배열 0번째 인덱스 증가 시킴
// 2. k = n 일 때 종이의 갯수를 구할 수 있음을 가정.
// 3. k = n+1 일때 정답 배열의 인덱스 값 출력
#include <iostream>
#include <cmath>

int ans[3];
int arr[2187][2187];
using namespace std;


void recursion(int r, int c, int n)
{
    int curnum = arr[r][c];
    int check = 0;
    for (int i = r; i < r + n; i++)
    {
        for (int j = c; j < c + n; j++)
        {
            if (curnum != arr[i][j])
            {
                check = 1;
                break;
            }
        }
        if (check)
            break;
    }
    if (check == 0)
        ans[curnum + 1]++;
    else
    {
        int next_n = n / 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                recursion(r + i * next_n, c + j * next_n, next_n);
            }
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    recursion(0, 0, n);
    for (int i = 0; i < 3; i++)
        cout << ans[i] << '\n'; 
    return (0);
}