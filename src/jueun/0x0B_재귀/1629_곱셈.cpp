#include <iostream>

using namespace std;

long long pow(long long a, long long b, long long c)
{
    if (b == 1)
        return a % c;

    long long tmp = pow(a, b / 2, c);
    tmp = tmp * tmp % c;
    if (b % 2 == 0)
        return tmp;
    else
        return tmp * a % c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b, c;

    cin >> a >> b >> c;

    cout << pow(a, b, c);

    return 0;
}
