// AC
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string func, str;
    int t, n, R, tmp, err;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        deque<int> DQ;
        R = 0;
        err = 0;
        cin >> func >> n >> str;

        /*      문자열에서 정수를 뽑아 deque에 push     */
        for (int i = 0; str[0] == '[' && i < (int)str.length(); i++)
        {
            tmp = 0;
            if (str[i] >= '0' && str[i] <= '9')
            {
                while (str[i] != ',' && str[i] != ']')
                    tmp = tmp * 10 + (str[i++] - '0');
                DQ.push_back(tmp);
            }
        }

        /*      함수들 실행     */
        for (auto j : func)
        {
            if (j == 'R')
                R += 1;
            else
            {
                if (DQ.empty())
                {
                    cout << "error\n";
                    err = 1;
                    break;
                }
                else if (R % 2 == 0)
                    DQ.pop_front();
                else
                    DQ.pop_back();
            }
        }

        /*      deque에 남은 element들 출력     */
        if (!err)
        {
            cout << '[';
            if (R % 2 == 0)
            {
                while (!DQ.empty())
                {
                    cout << DQ.front();
                    if (DQ.size() != 1)
                        cout << ',';
                    DQ.pop_front();
                }
            }
            else
            {
                while (!DQ.empty())
                {
                    cout << DQ.back();
                    if (DQ.size() != 1)
                        cout << ',';
                    DQ.pop_back();
                }
            }
            cout << "]\n";
        }
    }
}