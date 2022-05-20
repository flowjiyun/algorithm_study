#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    char str[101] = "";
    int result[26] = {};
    cin >> str;

    for (int i = 0; str[i]; i++)
        result[str[i] - 'a'] += 1;
    for (int i = 0; i < 26; i++)
        cout << result[i] << ' ';
}