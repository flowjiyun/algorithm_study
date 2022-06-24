#include <iostream>
#include <algorithm>
using namespace std;

int n, m, sum;
int a[1000000];
int b[1000000];
int ans[1000000];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    sum = n + m;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(b, b + m);

    int aidx = 0, bidx = 0;
    for (int i = 0; i < sum; i++)
    {
        if (bidx == m)
            ans[i] = a[aidx++];
        else if (aidx == n)
            ans[i] = b[bidx++];
        else if (a[aidx] <= b[bidx])
            ans[i] = a[aidx++];
        else 
            ans[i] = b[bidx++];     
    }
    for (int i = 0; i < sum; i++)
        cout << ans[i] << ' ';
}
