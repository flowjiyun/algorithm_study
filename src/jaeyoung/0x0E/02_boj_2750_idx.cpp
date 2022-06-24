#include <iostream>
using namespace std;

int n, tmp;
bool vis[2005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--)
    {
        cin >> tmp;
        vis[tmp + 1000] = 1;
    }
    
    for (int i = 0; i < 2005; i++)
    {
        if (vis[i])
            cout << i - 1000 << '\n';
    }
}