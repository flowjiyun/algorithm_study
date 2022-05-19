#include <iostream>

using namespace std;

int nb[26];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    char word[101];
    char alpha[26];
    for (int i = 0; i < 26; i++)
    {
        alpha[i] = 'a' + i;
    }
    cin >> word;
    for (int i = 0; word[i] != 0; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (word[i] == alpha[j])
            {
                nb[j]++;
            }
        }
    }
    for (int i = 0; i < 26; i++)
        cout << nb[i] << ' ';
}