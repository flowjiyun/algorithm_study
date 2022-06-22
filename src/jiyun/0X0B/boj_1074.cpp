//z
//1. n = 1일때 r행 c열의 방문 순서를 구할 수 있음.(자명함, 증명)
//2. n = k일때 r행 c열의 방문 순서를 구할 수 있다고 가정.
//3. n = k + 1 일때, n = k의 결과를 가지고 r행 c열의 방문 순서를 구할 수 있음(증명).
//--> 귀납적으로 n = k일때 r행 c열에서의 방문 순서를 구할 수 있음.
0 1 4 5
2 3 6 7

#include <iostream>
#include <cmath>

using namespace std;

int recursion(int n, int r, int c)
{
    if (n == 0)
        return 0;
    int half = static_cast<int>(pow(2, n - 1));
    if (r < half && c < half)
        return recursion(n - 1, r, c);
    else if (r < half && c >= half)
        return half * half + recursion(n - 1, r, c - half);
    else if (r >= half && c < half)
        return 2 * half * half + recursion(n - 1, r - half, c);
    else
        return 3* half * half + recursion(n - 1, r - half, c - half);
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r, c;
    cin >> n >> r >> c;
    int ans = recursion(n, r, c);
    cout << ans;
    return (0);
}