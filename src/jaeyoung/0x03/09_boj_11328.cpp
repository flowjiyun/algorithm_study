#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int i;
    int num[26] = {};
    int sum;
    string s1, s2;
    
    i = 0;
    cin >> n;
    while (n--)
    {
        cin >> s1 >> s2;

        for(auto c : s1)
            num[c - 'a']++;
        for(auto c : s2)
            num[c - 'a']--;
        sum = 0;
        for(auto c : num)
        {
            if (c < 0)
                c *= -1;
            sum += c;
        }
        if (sum)
            cout << "Impossible" << '\n';
        else 
            cout << "Possible" << '\n';
        for(auto &c : num)
            c = 0;
    }
}
    
