#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string word;
    cin >> word;
    list<char> l;
    for (auto c : word)
        l.push_back(c);
    
    auto cursor = l.end();
    int nb;
    cin >> nb;
    while (nb--)
    {
        char op;
        cin >> op;
        if (op == 'P') 
        {
        char add;
        cin >> add;
        l.insert(cursor, add);
        }
        else if (op == 'L') 
        {
        if (cursor != l.begin()) 
            cursor--;
        }
        else if (op == 'D') 
        {
        if (cursor != l.end()) 
            cursor++;
        }
        else 
        { 
        if (cursor != l.begin()) 
        {
            cursor--;
            cursor = l.erase(cursor);
        }
        }
    }
    for (auto c : l)
        cout << c;
    return (0);
}