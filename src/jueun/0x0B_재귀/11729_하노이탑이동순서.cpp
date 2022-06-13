#include <iostream>
#include <math.h>
using namespace std;

void hanoi(int a, int b, int n)
{
    if (n == 1)
    {
        cout << a << " " << b << "\n";
        return;
    }

    hanoi(a, 6 - a - b, n - 1);
    cout << a << " " << b << "\n";
    hanoi(6 - a - b, b, n - 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n;

    k = pow(2, n) - 1;
    cout << k << "\n";
    hanoi(1, 3, n);

    return 0;
}
