#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    for (int i = 0; q.size() > 1; i++)
    {
        if (i % 2 == 0)
        {
            q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
    cout << q.front();
}