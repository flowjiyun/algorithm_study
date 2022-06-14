//색종이 만들기
//boj_1780 유사 문제
//n = 1일 때 종이의 색판별 후 종이 갯수 셀 수 있음.(정답 배열에 갯수 저장)
//n = k일 때 종이의 색판별 후 종이 갯 수 셀 수 있다 가정.
//n = k+1 일때 셀수 있음.

#include <iostream>

using namespace std;
int ans[2];
int arr[128][128];

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
        ans[curnum]++;
    else
    {
        int next_n = n / 2;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
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
    for (int i = 0; i < 2; i ++)
        cout << ans[i] << '\n';
    return (0);
}