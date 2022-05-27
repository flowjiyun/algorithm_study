#include <iostream>
#include <stack>
#include <list>
using namespace std;

int arr[100000];
stack<int> s;
list<char> pm;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int i;
    int value;

    i = 0;
    value = 1;
    cin >> n;
    while (i < n)
        cin >> arr[i++];
    i = 0;
    while (i < n)
    {
        if (s.empty())
        {
            s.push(value++);
            pm.push_back('+');
        }
        while (s.top() != arr[i])
        {
            if (s.top() > arr[i])
            {
                cout << "NO";
                return (0);
            }
            s.push(value++);
            pm.push_back('+');
        }
        while (!s.empty() && s.top() == arr[i])
        {
            s.pop();
            pm.push_back('-');
        }
        i++;
    }
        for (auto c : pm)
            cout << c << '\n';
}