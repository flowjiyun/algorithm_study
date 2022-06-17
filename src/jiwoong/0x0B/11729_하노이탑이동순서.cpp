#include <iostream>
using namespace std;

// src -> des | oth
int cnt(int n){
    if (n == 1) return 1;
    if (n == 2) return 3;
    return 2 * cnt(n - 1) + 1;
}

void move(int n, int src, int oth, int des){
    if(n == 1){ 
        cout << src << " " << des << "\n";
        return;
    }
    if(n == 2){
        cout << src << " " << oth << "\n";
        cout << src << " " << des << "\n";
        cout << oth << " " << des << "\n";
        return;
    }
    move(n - 1, src, des, oth); // n - 1 개 : src -> oth
    move(1, src, oth, des);     // 제일큰거 : src -> des
    move(n - 1, oth, src, des); // n - 1 개 : oth -> des
}

// cnt(1) : 1
// cnt(2) : 3
// cnt(3) : 2*cnt(2) + 1

// cnt(n) : 2*cnt(n - 1) + 1
// cnt(n) - 1 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    cout << cnt(N) << "\n";
    move(N, 1, 2, 3);
    return 0;
}