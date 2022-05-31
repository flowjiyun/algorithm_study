#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        string p, arr = "", tmp = "";
        int n;
        deque<int> dq;
        cin >> p >> n >> arr;

        for (int i = 0; i < arr.size(); i++)
        {
            if (isdigit(arr[i]))
                tmp += arr[i];
            else
            {
                if (tmp.size() != 0)
                {
                    dq.push_back(stoi(tmp));
                    tmp = "";
                }
            }
        }
        int error = 0;
        int reverse = 0;

        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] == 'R')
                reverse++;
            else
            {
                if (dq.empty())
                {
                    cout << "error\n";
                    error = 1;
                    break;
                }
                if (reverse % 2 == 0)
                {
                    dq.pop_front();
                }
                else
                {
                    dq.pop_back();
                }
            }
        }
        if (!error)
        {
            cout << "[";
            if (reverse % 2 != 0)
            {
                for (int i = dq.size() - 1; i >= 0; i--)
                {
                    cout << dq[i];
                    if (i != 0)
                        cout << ",";
                }
            }
            else
            {
                for (int i = 0; i < dq.size(); i++)
                {
                    cout << dq[i];
                    if (i != dq.size() - 1)
                        cout << ",";
                }
            }
            cout << "]" << '\n';
        }
    }
}