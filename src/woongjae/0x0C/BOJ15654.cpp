#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[8];
int ans[8];
int ck[8];
void func(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (ck[i] == 0)
        {
            ck[i] = 1;
            ans[cnt] = a[i];
            func(cnt + 1);
            ck[i] = 0;
        }

    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    func(0);
}