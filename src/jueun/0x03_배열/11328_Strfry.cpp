#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, check;
    string str1, str2;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<int> v(26);
        check = 1;

        cin >> str1 >> str2;

        for (int i = 0; i < str1.size(); i++)
            v[str1[i] - 'a']++;
        for (int i = 0; i < str2.size(); i++)
            v[str2[i] - 'a']--;

        for (int i = 0; i < 26; i++)
        {
            if (v[i])
            {
                check = 0;
                break;
            }
        }

        if (check)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }

    return 0;
}