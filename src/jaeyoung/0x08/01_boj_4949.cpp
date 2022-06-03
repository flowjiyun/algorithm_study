#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s = "";

    while (s != ".")
    {
        getline(cin, s);
        if (s == ".")
            break;
        deque <char> dq;
        int error = 0;
        for (auto a : s)
        {
            if (a == '(' || a == '[')
                dq.push_back(a);
            else if (a == ')')
            {
                if (!dq.empty() && dq.back() == '(')
                    dq.pop_back();
                else
                    {
                        error = 1;
                        break;
                    }
            }
            else if (a == ']')
            {
                if (!dq.empty() && dq.back() == '[')
                    dq.pop_back();
                else
                {
                    error = 1;
                    break;
                }
            }
        }
        if (error || !dq.empty())
            cout << "no\n";
        else
            cout << "yes\n";
    }
}