#include <iostream>
#include <stack>
#include <utility>
using namespace std;

stack<pair<int, int>> s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int i;
    int new_top;

    s.push({100000001, 0});
    cin >> n;
    i = 1;
    while (i <= n)
    {
        cin >> new_top;
        while (s.top().first < new_top)
            s.pop();
        cout << s.top().second << ' ';
        s.push({new_top, i});
        i++;
    }
}