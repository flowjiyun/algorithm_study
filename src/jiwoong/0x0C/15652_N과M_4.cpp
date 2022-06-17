#include <iostream>
#include <vector>
using namespace std;

vector<int> seq;
int N, M;

void select(const int& start, const int& depth){
    if(depth > M){
        for(int i = 0 ; i < M ; i++){
            cout << seq[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = start; i <= N; i++){
        seq[depth - 1] = i;
        select(i, depth + 1);  
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    seq.resize(N);
    select(1, 1);
    return 0;
}