#include <iostream>
#define MAX_SIZE 100000
using namespace std;

int arr[MAX_SIZE];
int pos = -1;

void push(int x)
{
    if (pos != MAX_SIZE - 1)
        arr[++pos] = x;
}

int pop()
{
    if (pos != -1)
        return (arr[pos--]);
    else
        return (-1);
}

int size()
{
    return (pos + 1);
}

int empty()
{
    if (pos != -1)
        return 0;
    else 
        return 1;
}

int top()
{
    if (!empty())
        return (arr[pos]);
    else
        return (-1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int i;
    int x;
    string s;
    
    cin >> n;
    i = 0;
    while (i < n)
    {
        cin >> s;
        if (s == "push")
        {
            cin >> x;
            push(x);
        }
        if (s == "pop")
            cout << pop() << '\n';
        if (s == "size")
            cout << size() << '\n';
        if (s == "empty")
            cout << empty() << '\n';
        if (s == "top")
            cout << top() << '\n';
        i++;
    }
}