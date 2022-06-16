#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    long long ans;
    vector<int> v(10);

    cin >> a >> b >> c;
    ans = a * b * c;

    while (ans > 0)
    {
        int n = ans % 10;
        ans = ans / 10;

        v[n]++;
    }

    for (int i = 0; i < 10; i++)
        cout << v[i] << "\n";

    return 0;
}