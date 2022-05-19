#include <iostream>
#include <string>
using namespace std;

int alpha[26];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    string a;
    string b;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
    

        for (int i = 0; i < a.size(); i++)
        {
            alpha[a[i] - 'a']++;
        }
        for (int i = 0; i < b.size(); i++)
        {
            alpha[b[i] - 'a']--;
        }
        int check = 0;
        for (int i = 0; i < 26; i++)
        {
            if (alpha[i] != 0)
            {
                check = 1;
                break;
            }
        }
        if (check  == 1)
            cout << "Impossible" << '\n';
        else
            cout << "Possible" << '\n';
    }
    return (0);
}