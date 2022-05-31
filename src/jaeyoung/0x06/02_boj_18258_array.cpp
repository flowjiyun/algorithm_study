#include <iostream>
using namespace std;

int q[2000002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int head = 0;
    int tail = 0;

    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "push")
            cin >> q[tail++];
        else if (s == "pop")
            cout << (head == tail ? -1 : q[head++]) << '\n';
        else if (s == "size")
            cout << (tail - head) << '\n';
        else if (s == "empty")
            cout << (head == tail) << '\n';
        else if (s == "front")
            cout << (head == tail ? -1 : q[head]) << '\n';
        else if (s == "back")
            cout << (head == tail ? -1 : q[tail - 1]) << '\n';
    }

}