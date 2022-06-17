#include <iostream>
#include <vector>
using namespace std;

void select(vector<int>& selected, const vector<int> &S,
const int & start, const int & depth, const int & K){
    if(depth > 6){
        for(auto & ele : selected){
            cout << ele << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = start; i < K ; i++){
        selected[depth - 1] = S[i];
        select(selected, S, i + 1, depth + 1, K);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int K;
    cin >> K;
    while(K != 0){
        vector<int> S(K);
        vector<int> selected(6);
        for(int i = 0 ; i < K ;i++){
            cin >> S[i];
        }
        select(selected,S,0,1,K);
        cout << "\n";
        cin >> K;
    }
    return 0;
}