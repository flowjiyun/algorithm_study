#include <iostream>
#include <deque>
using namespace std;

void ft_putnbr(string &s, deque<int> &dq)
{
    int i;
    int num;

    i = 1;
    num = 0;
    while (i + 1 < s.size())
    {
        if (s[i] == ',')
        {
            dq.push_back(num);
            num = 0;
        }
        else
            num = num * 10 + (s[i] - '0');
        i++;
    }
    if (num !=0)
        dq.push_back(num);

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--)
    {
        deque<int> dq = {};
        string p, s;
        cin >> p >> n >> s;

        ft_putnbr(s, dq);
        int flag = 0, cnt = 0, error = 0;
        for (auto c : p)
        {
            if (c == 'R')
            {
                cnt++;
                flag = cnt % 2;
            }
            else if (c == 'D')
            {
                if (dq.empty())
                {
                    error = 1;
                    break;
                }
                else if (flag == 1)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }
        if (!error)
        {
            cout << '[';

            while (!dq.empty())
            {
                if (flag == 1)
                {
                    cout << dq.back();
                    if (dq.size() != 1)
                        cout << ',';
                    dq.pop_back();
                }
                else
                {
                    cout << dq.front();
                    if (dq.size() != 1)
                        cout << ',';
                    dq.pop_front();
                }
            }
            cout << "]\n";
        }
        else
            cout << "error\n";
    }
}
