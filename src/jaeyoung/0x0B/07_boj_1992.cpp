#include <iostream>
using namespace std;

int board[64][64];
int n;

void solve(int x, int y, int size)
{
    if (size == 1)
    {
        cout << board[x][y];
        return;
    }

    bool zero = true, one = true;
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (board[i][j])
                zero = false;
            else 
                one = false;
        }
    }
    if (zero)
        cout << 0;
    else if (one)
        cout << 1;
    else
    {
        cout << "(";
        solve(x, y, size / 2);           
        solve(x, y + n / 2, size / 2);       
        solve(x + n / 2, y, size /2);        
        solve(x + n / 2, y + n / 2, size / 2); 
        cout << ")";
    }
    return;

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
            for (int j = 0; j < n; j++)
                board[i][j] = s[j] - '0';
    }
    solve(0, 0, n);
}