#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[2][26] = {}, result;
    string s1, s2;

    cin >> s1 >> s2;
    for (int i = 0; s1[i]; i++)
        arr[0][s1[i] - 'a']++;

    for (int i = 0; s2[i]; i++)
        arr[1][s2[i] - 'a']++;

    for (int i = 0; i < 26; i++)
        result += abs(arr[0][i] - arr[1][i]);

    cout << result;
}