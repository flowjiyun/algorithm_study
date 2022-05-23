#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char str[105] = {'\0'};
    int num[30] = {0};
    cin >> str;
    for(int i = 0; str[i]!='\0';i++){
        num[str[i]-'a']++;
    }
    for(int i = 0; i <= 'z' - 'a' ; i++){
        cout << num[i] << " ";
    }
    return 0;
}