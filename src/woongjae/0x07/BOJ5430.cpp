#include <bits/stdc++.h>
using namespace std;


int main()
{
    int T;
    int n;
    int i;
    int cnt;
    int tmp;
    int flag;
    string p;
    string num;
    deque <int> dq;

    cin >> T;
    while (T--)
    {
        cin >> p;
        cin >> n;
        cin >> num;
        i = 0;
        tmp = 0;
        flag = 1;
        while (num[i])
        {
            if (num[i] == '[' )
                i++;
            if (num [i] >= '0' && num[i] <= '9')
            {
                tmp = tmp * 10 +  num[i] - '0';
                i++;    
            }
            if (num[i] == ',' || num[i] == ']')
            {
                if (num[i - 1] == '[')
                {
                    flag = 1;
                    break;
                }
                dq.push_back(tmp);
                tmp = 0;
                i++;
            }
        }
        i = 0;
        cnt = 0;
        while (p[i])
        {
            if (p[i] == 'D' && dq.empty())
            {
                flag = 0;
                break;
            }
            if (p[i] == 'R')
            {
                cnt++;
            }
            else if (p[i] == 'D')
            {
                if (cnt % 2 == 0)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
            i++;
        }
        
        if (dq.size() != 0)
        {
            cout << "[";
            while (dq.size())
            {
                if (cnt % 2 == 0)
                {
                    cout << dq.front();
                    dq.pop_front();
                }
                else
                {
                    cout << dq.back();
                    dq.pop_back();
                }
                if (dq.size())
                    cout << ",";
            }
            cout << "]" << '\n';
        }
        else if (flag == 1 && dq.size() == 0)
        {
            cout << "[]" << '\n';
            flag = 0;
        }
        else
            cout << "error" << '\n';
    }
    return (0);
}