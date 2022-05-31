#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main(void)
{
    int n;
    int i;
    int x;

    cin >> n;
    i = 1;
    while (i <= n)
        q.push(i++);
    i = 1;
    while (i < n)
    {
        q.pop();
        x = q.front();
        q.pop();
        q.push(x);
        i++;
    }
    cout << q.front();
}