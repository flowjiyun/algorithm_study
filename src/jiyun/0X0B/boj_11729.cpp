//하노이의 탑
// 귀납적 사고 기초문제
// n개 원판을 옮기는데  n -1 --- 1
// 
#include <iostream>
#include <cmath>

using namespace std;

void recursive(int a, int b, int n)
{
    if (n == 1)
    {
        cout << a << ' ' << b << '\n';
        return;
    }
    recursive(a, 6 - a - b, n - 1);
    cout << a << ' ' << b << '\n';
    recursive(6 - a - b, b, n - 1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = static_cast<int>(pow(2, n) - 1); // n 옮기는 횟 수는 2^ n - 1
    cout << cnt << '\n';
    recursive(1, 3, n);
    return (0);
}