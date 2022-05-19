#include <iostream>

using namespace std;

int nb[26];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    char word[101];
    cin >> word;
    for (int i = 0; word[i] != 0; i++)
    {
        nb[word[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        cout << nb[i] << ' ';
    return (0);
}