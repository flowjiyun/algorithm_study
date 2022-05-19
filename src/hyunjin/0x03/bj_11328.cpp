#include <iostream>
using namespace std;

int ispossible()
{
    int aarr[26] = {};
    int barr[26] = {};
    string a, b;
    cin >> a >> b;
    int alen = 0, blen = 0;
    while (a[alen]){
        aarr[a[alen] - 'a']++;
        alen++;
    }
    while (b[blen]){
        barr[b[blen] - 'a']++;
        blen++;
    }

    for(int i = 0; i < 26; i++){
        if (aarr[i] != barr[i]) return (1);
    }
    return (0);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        if (ispossible() == 0) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}
