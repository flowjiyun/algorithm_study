#include <iostream>
using namespace std;

int cnt[2000002];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 0 ; i < N; i++){
        int ipt;
        cin >> ipt;
        cnt[ipt + 1000000] += 1;
    }
    for(int i = 0; i < 2000001; i++){
        for(int j = 0; j < cnt[i] ; j++){
            cout << i - 1000000 << "\n";
        }
    }
    return 0;
}