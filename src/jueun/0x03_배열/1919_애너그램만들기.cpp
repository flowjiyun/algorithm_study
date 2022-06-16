#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt;
    vector<int> v(26);
    string str1, str2;

    cin >> str1;
    cin >> str2;

    for (int i = 0; i < str1.size(); i++)
        v[str1[i] - 'a']++;
    for (int i = 0; i < str2.size(); i++)
        v[str2[i] - 'a']--;

    cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (v[i])
            cnt += abs(v[i]);
    }

    cout << cnt;
    return 0;
}