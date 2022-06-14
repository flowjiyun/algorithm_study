//쿼드 트리
#include <iostream>
#include <string>

using namespace std;
string arr[64];

void recursion(int r, int c, int n)
{
    //cout << '(';
    char curnum = arr[r][c];
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
        cout << static_cast<char>(curnum);
    else
    {
        int next_n = n / 2;
        cout << '(';
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                recursion(r + i * next_n, c + j * next_n, next_n);
        }
        cout << ')';
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
        cin >> arr[i];
    }
    recursion(0, 0, n);
    
    return (0);
}