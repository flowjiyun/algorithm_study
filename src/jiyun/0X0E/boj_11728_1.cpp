#include <iostream>

using namespace std;
int a[1000000];
int b[1000000];
int c[2000000];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    int aindx = 0;
    int bindx = 0;
    for (int i = 0; i < n + m; i++)
    {
        if (aindx == n)
            c[i] = b[bindx++];
        else if (bindx == m)
            c[i] = a[aindx++];
        else if (a[aindx] <= b[bindx])
            c[i] = a[aindx++];
        else
            c[i] = b[bindx++];
    }
    for (int i = 0; i < n + m; i++)
        cout << c[i] << ' ';
    return (0);

}