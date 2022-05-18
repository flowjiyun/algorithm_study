#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int alphabets[26];
        for (int i = 0 ; i < 26; i++){
            alphabets[i] = 0;
        }
        char s1[1001], s2[1001];
        cin >> s1;
        for(int i = 0 ; s1[i] != '\0'; i++){
            alphabets[s1[i] - 'a']++;
        }
        cin >> s2;
        for(int i = 0 ; s2[i] != '\0'; i++){
            alphabets[s2[i] - 'a']--;
        }
        int j;
        for(j = 0 ; j < 26; j++){ 
            if(alphabets[j] != 0)
            {
                cout << "Impossible\n";
                break;
            }
        }
        if (j == 26)
            cout << "Possible\n";
    }
    return 0;
}