#include <iostream>
using namespace std;

int main()
{
    string a, b;
    int arr[26] = {};
    cin >> a >> b;

    for (auto c : a) arr[c - 'a']++;
    for (auto c : b) arr[c - 'a']--;

    int cnt = 0;
    for (int i = 0; i < 26; i++){
        if (arr[i] != 0) 
            cnt += abs(arr[i]);
    }
    cout << cnt;
}
