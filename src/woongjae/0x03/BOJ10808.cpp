#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char s[100];
    char alphabet[26];
    int flag[26];
    int i, j;

    i = 0;
    cin >> s;
    while(i < 26)
    {
        flag[i] = 0;
        alphabet[i] = 'a' + i;
        i++;
    }
    i = 0;
    while (i < strlen(s))
    {
        j = 0;
        while (j < 26)
        {
            if (s[i] == alphabet[j])
                flag[j]++;
            j++;
        }
        i++;
    }
    i = 0;
    while(i < 26)
    {
        cout << flag[i] << " ";
        i++;
    }
    return (0);
}