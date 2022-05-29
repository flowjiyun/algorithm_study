#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;

    cin >> t;

    while (t--)
    {
        string str, s;
        cin >> str;
        cin >> n;
        cin >> s;

        deque<int> d;
        bool check = true;

        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] != '[' && s[i] != ']' && s[i] != ',')
            {
                int num = 0;

                while (s[i] != '[' && s[i] != ']' && s[i] != ',')
                {
                    num += (s[i] - '0');
                    num *= 10;
                    i++;
                }
                num /= 10;
                d.push_back(num);
            }
        }

        bool r_check = true;
        for (int i = 0; i < str.size(); i++)
        {

            if (str[i] == 'R')
            {
                r_check = !r_check;
            }

            else if (str[i] == 'D')
            {
                if (d.empty())
                {
                    cout << "error\n";
                    check = false;
                    break;
                }
                else
                {
                    if (r_check)
                        d.pop_front();
                    else
                        d.pop_back();
                }
            }
        }

        if (check)
        {
            cout << "[";

            if (!r_check)
            {

                if (!d.empty())
                {
                    cout << d.back();
                    d.pop_back();
                }

                for (int i = d.size() - 1; i >= 0; i--)
                {
                    cout << ",";
                    cout << d[i];
                }
            }

            else
            {
                if (!d.empty())
                {
                    cout << d.front();
                    d.pop_front();
                }

                for (int i = 0; i < d.size(); i++)
                {
                    cout << ",";
                    cout << d[i];
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}
