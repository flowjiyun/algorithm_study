#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int alpha[26] = {};
    string a;
    string b;
    int check = 0;

    cin >> a >> b;
    for (int i = 0; i < a.size(); i++)
        alpha[a[i] - 'a']++;
    for (int i = 0; i < b.size(); i++)
        alpha[b[i] - 'a']--;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] != 0)
        {
            if (alpha[i] < 0)
                check += -alpha[i];
            else
                check += alpha[i];
        }
    } 
    cout << check;
    return (0);   
}