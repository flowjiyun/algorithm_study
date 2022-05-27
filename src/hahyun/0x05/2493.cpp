#include <iostream>
#include <stack>
#include <utility> //pair 사용 시 필요
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    stack<pair<int, int> > s;
    /* stack pair 값을 할당
    1. s.push(make_pair(a, b))
    2. s.push({a, b})
       stack pair 값을 참조
    1. s.top().first , s.top().second */

    cin >> n;
    int arr[n];

    for (int i = 1; i <= n; i++)
    {
        cin >> x;

        if (s.empty())
        {
            cout << 0 << ' ';
        }
        else
        {
            while (!s.empty())
            {
                if (s.top().second > x)
                {
                    cout << s.top().first << ' ';
                    break;
                }
                else
                {
                    s.pop();
                }
            }
            if (s.empty())
                cout << 0 << ' ';
        }
        s.push(make_pair(i, x));
    }
}