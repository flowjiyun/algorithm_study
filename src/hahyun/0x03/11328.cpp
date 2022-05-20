#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, result;
    string a, b;
    int arr[26] = {};
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        for (int j = 0; j < a.size(); j++)
            arr[a[j] - 'a']++;
        for (int j = 0; j < b.size(); j++)
            arr[a[j] - 'a']--;
        result = 0;
        for (int j = 0; j < 26; j++)
            if (arr[j] != 0)
                result = 1;
        if (!result)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}