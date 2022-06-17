#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> seq;
vector<int> num;
vector<bool> vis;
int N, M;

void select(const int& start, const int& depth){
    if(depth > M){
        for(int i = 0 ; i < M ; i++){
            cout << seq[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < N; i++){
        if(vis[i] == false){
            seq[depth - 1] = num[i];
            vis[i] = true;
            select(i + 1, depth + 1);  
            vis[i] = false;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    vis.resize(N);
    seq.resize(N);
    num.resize(N);
    for(int i = 0 ; i < N; i++){
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    select(1, 1);
    return 0;
}