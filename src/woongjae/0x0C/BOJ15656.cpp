#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[8];
int ans[8];
int ck[8];
void func(int num)
{
    if (num == m)
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

        ans[num] = a[i];
        func(num + 1);
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