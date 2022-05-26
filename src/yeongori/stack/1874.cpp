// 스택 수열
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int max, idx = 0;
    string str;
    cin >> max;
    stack<int> s, k;

    int perm[max];
    for (int i = 0; i < max; i++)
        cin >> perm[i];

    for (int i = 1; i < max + 1; i++)
    {
        s.push(i);
        str.append("+\n");
        while (!s.empty() && s.top() == perm[idx])
        {
            str.append("-\n");
            k.push(s.top());
            s.pop();
            idx++;
        }
    }

    if ((int)k.size() == max)
        cout << str;
    else
        cout << "NO\n";
    return 0;
}