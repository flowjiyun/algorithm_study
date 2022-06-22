//곱셈
#include <iostream>

using namespace std;

long long solve(long long A, long long B, long long C)
{
    if (B == 1) // basecondition
        return A % C;
    long long result = solve(A, B / 2, C);
    result = result * result % C;
    if (B % 2 == 0)
        return result;
    else
        return result * A % C;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long A, B, C;
    cin >> A >> B >> C;
    long long ans = solve(A, B, C);
    cout << ans;
    return (0);
}