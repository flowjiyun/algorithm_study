#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int N, cnt;
    cin >> N;

    int arr[26] = {};
    int res[N];

    for (int i = 0; i < N; i++) {
        string s1, s2;
        int cnt = 0;
        int arr[26] = {};
        res[i] = 1;

        cin >> s1 >> s2;
        for (int j: s1)
            arr[j - 'a']++;

        for (int k: s2)
            arr[k - 'a']--;

        for (int l: arr)
            if (l != 0) res[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        if (res[i]) cout << "Possible\n";
        else cout << "Impossible\n";
    }

    return (0);
}