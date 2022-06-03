#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, cnt = 0;

    cin >> n;
    while (n--)
    {
        deque<char> dq;
        string s;
        cin >> s;
        if (!(s.size() % 2))
        {
            int i = 0, error = 1;
            while (i + 1 < s.size())
            {
                dq.push_back(s[i]);
                if (!dq.empty() && error == 0)
                    dq.pop_back();
                if (!dq.empty() && dq.back() == s[i + 1])
                {
                    error = 0;
                    dq.pop_back();
                }
                else
                    error = 1;
                i++;
            }
            if (dq.empty())
                cnt++;
        }
    }
    cout << cnt;
}
