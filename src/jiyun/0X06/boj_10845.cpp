#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int nb;
    queue<int> Q;
    string cmd;
    cin >> nb;
    while (nb--)
    {
       cin >> cmd;
       if (cmd == "push")
       {
           int x;
           cin >> x;
           Q.push(x); 
       } 
       else if (cmd == "pop")
       {
           if (!Q.empty())
           {
               cout << Q.front() << '\n';
               Q.pop();
           }
           else
           {
               cout << -1 <<'\n';
           }
       }
       else if (cmd == "size")
       {
           cout << Q.size() << '\n';
       }
       else if (cmd == "empty")
       {
           if (Q.empty())
           {
               cout << 1 << '\n';
           }
           else
           {
               cout << 0 << '\n';
           }
       }
       else if (cmd == "front")
       {
           if (!Q.empty())
           {
               cout << Q.front() << '\n';
           }
           else
           {
               cout << -1 << '\n';
           }
       }
       else
       {
           if (!Q.empty())
           {
               cout << Q.back() << '\n';
           }
           else
           {
               cout << -1 << '\n';
           }
       }
    }
    return (0);
}