#include <iostream>
#include <vector>
#include <string>
using namespace std;

int ans = 0;
int N; 
vector<bool> canPut[3];

void putQueen(int row){
    if(row == N){
        ans += 1;
        return;
    }
    for(int col = 0; col < N ; col++){
        if(canPut[0][col] && canPut[1][row + col] && canPut[2][row - col + N - 1]){
            canPut[0][col] = false;
            canPut[1][row + col] = false;
            canPut[2][row - col + N - 1] = false;
            putQueen(row + 1);
            canPut[0][col] = true;
            canPut[1][row + col] = true;
            canPut[2][row - col + N - 1] = true;
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0 ; i < 3 ;i++) canPut[i].assign(30, true);
    putQueen(0);
    cout << ans;
    return 0;
}