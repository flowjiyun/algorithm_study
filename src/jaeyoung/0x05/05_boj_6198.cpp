#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long int cnt;
    int new_top;
    int i;

    cin >> n;
    s.push(0);
    cnt = 0;
    i = 0;
    while (i < n)
    {
        cin >> new_top;
        while (!s.empty() && s.top() <= new_top)
            s.pop();
        if (!s.empty() && s.top() > new_top)
            cnt += s.size();
        s.push(new_top);
        i++;
    }
    cout << cnt;
}