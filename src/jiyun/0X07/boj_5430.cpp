#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    string func;
    int n;
    int nb;
    char trash;
    cin >> T;
    while(T--)
    {
        deque<int> D;  
        cin >> func;
        cin >> n;
        if (n == 0)
        {
            cin >> trash >> trash;
        }
        else
        {
            cin >> trash;
            for (int i = 0; i < n; i++)
            {
                cin >> nb >> trash;
                D.push_back(nb);
            }
        }
        int flag = 1;
        int cnt_r = 0;
        int error = 0;
        for (int i = 0; i < func.length(); i++)
        {
            if (!D.empty())
            {
                if(func[i] == 'D')
                {
                    if (flag == 1)
                    {
                        D.pop_front();
                    }
                    else
                        D.pop_back();
                }
                else
                {
                    flag *= -1;
                    cnt_r++;
                }
            }
            else
            {
                if (func[i] == 'R')
                    continue;
                else
                {
                    error = 1;
                    break;
                }
            }
        }
        if (error)
        {
            cout << "error" << '\n';
        }
        else
        {
            if (cnt_r % 2 == 1)
            {
                reverse(D.begin(), D.end());
            }
            cout << '[';
            for (int i = 0; i < D.size(); i++)
            {
                cout << D[i];
                if (i != D.size() - 1)
                    cout << ',';
            }
            cout << ']' << '\n';
        }
    }
    return(0);
}