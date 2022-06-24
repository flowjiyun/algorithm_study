#include <iostream>
#include <vector>

using namespace std;
vector<int> cnt(10001);

int main(){
    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int ipt;
        cin >> ipt;
        cnt[ipt] += 1;
    }
    for(int i = 1; i <= 10000 ; i++){
        for(int j = 0 ; j < cnt[i]; j++){
            cout << i << "\n";
        }
    }
    return 0;
}