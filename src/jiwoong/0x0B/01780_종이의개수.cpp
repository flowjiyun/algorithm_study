#include <iostream>
#include <vector>
using namespace std;

int ans[3];
vector<vector<int>> paper;

bool isValid(int sr, int sc, int size){
    int id = paper[sr][sc];
    for(int r = sr ; r < sr + size; r++){
        for(int c = sc ; c < sc + size; c++){
            if(paper[r][c] != id) return false;
        }
    }
    ans[id + 1] += 1;
    return true;
}

void collect(int sr, int sc, int size){
    if(size == 1){
        ans[paper[sr][sc] + 1] += 1;
        return;
    }
    for(int r = sr; r < sr + size; r += size / 3){
        for(int c= sc; c < sc + size; c += size / 3){
            if(!isValid(r, c, size / 3)){
                collect(r, c, size / 3);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    paper.resize(N);
    for(auto & row : paper){
        row.resize(N);
        for(auto & ele : row) cin >> ele;
    }
    if(!isValid(0, 0, N)){
        collect(0, 0, N);
    }
    for(auto & ele : ans){
        cout << ele << "\n";
    }
    return 0;
}