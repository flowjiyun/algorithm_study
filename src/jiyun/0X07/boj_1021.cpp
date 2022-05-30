#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> D;
    int N;
    int M;
    int cnt = 0;
    int nb;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        D.push_back(i);
    while (M--)
    {
        cin >> nb;
        if (D.front() != nb)
        {
            int index = 0;
            while (D[index] != nb)
                index++;
            if (index + 1 <= (D.size() / 2) + 1)
            {
                while (D.front() != nb)
                {
                    D.push_back(D.front());
                    D.pop_front();
                    cnt++;
                }
                D.pop_front();
            }
            else
            {
                while (D.front() != nb)
                {
                    D.push_front(D.back());
                    D.pop_back();
                    cnt++;
                }
                D.pop_front();
            }
        }
        else
            D.pop_front();
    }
    cout << cnt;
    return (0);
}