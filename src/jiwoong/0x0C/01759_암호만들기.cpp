#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int L, C, ans = 0;
vector<char> charset;
string passwd;

int isJa(char ch){
    switch(ch){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return false;
        default:
            return true;
    }
    return true;
}

void select(int start, int len, int ja, int mo){
    if(len == L){
        if(ja >= 2 && mo >= 1) cout << passwd << "\n";
        return ;
    }
    passwd[len] = charset[start];
    if(start + 1 <= C){
        select(start + 1, len + 1, ja + isJa(charset[start]), mo + !isJa(charset[start]));
        select(start + 1, len, ja, mo);
    }
}

int main(){
    cin >> L >> C;
    charset.resize(C);
    passwd.resize(L);
    for(auto & ele : charset) cin >> ele;
    sort(charset.begin(), charset.end());
    // for(int s = 0 ; s <= C - L; s++)
    select(0, 0, 0, 0);
    return 0;
}