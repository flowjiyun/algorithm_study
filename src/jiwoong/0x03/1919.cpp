#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
    string s1,s2;
    int ans = 0;
    cin >> s1 >> s2;
    int alphabet[26];
    fill(alphabet, alphabet + 26, 0);
    for (auto& ch : s1){
        alphabet[ch - 'a']++;
    }
    for (auto& ch : s2){
        alphabet[ch - 'a']--;
    }
    for (auto& num : alphabet){
        ans += abs(num);
    }
    cout << ans;
    return 0;
}