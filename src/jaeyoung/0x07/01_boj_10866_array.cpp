#include <iostream>
using namespace std;

const int MAX = 10005;
int dq[2*MAX + 1];
int head = MAX, tail = MAX;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "push_front")
        {
            cin >> x;
            dq[--head] = x;
        }
        else if (s == "push_back")
        {
            cin >> x;
            dq[tail++] = x;
        }
        else if (s == "pop_front")
            cout << (tail == head ? -1 : dq[head++]) << '\n'; 
        else if (s == "pop_back")
            cout << (tail == head ? -1 : dq[--tail]) << '\n'; 
        else if (s == "size")
            cout << (tail - head) << '\n';
        else if (s == "empty")
            cout << (tail == head) << '\n';
        else if (s == "front")
            cout << (tail == head ? -1 : dq[head]) << '\n';
        else
            cout << (tail == head ? -1 : dq[tail - 1]) << '\n';
    }
}
