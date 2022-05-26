#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> value;
    stack<int> index;
    int i = 0;
    int nb;
    cin >> nb;
    value.push(0);   
    index.push(1);
    while (nb--)
    {
        int height;
        cin >> height;
        
        if (height > value.top())
        {
            while (!value.empty() && value.top() < height)
            {
                value.pop();
                index.pop();
            }
            if (value.empty())
            {
                cout << 0 << ' ';
            }
            else
            {
               cout << index.top() << ' '; 
            }
        }
        else
        {
            cout << index.top() << ' ';
        } 
        value.push(height);
        index.push(++i); 
    }
    return (0);
}