#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

int N;
int ans = 0;
vector<vector<int>> possible;

vector<bool> di; // r - c + N - 1 가 일정
// 대각선 b 선택 여부

void select(int b, int cnt){
    // r + c == b 
    if(b >= 2 * N - 1){
        ans = max(ans, cnt);
        return;
    }
    // cout << b << " " << cnt << "\n";
    select(b + 1, cnt);
    for(int r = 0; r < N; r++){
        int c = b - r;
        if( c < 0 || c >= N ) continue;
        // cout << "possible : " << possible[r][c] << " d : " << di[r - c + N - 1] << "\n";
        if((possible[r][c] == 1) && !di[r - c + N - 1]){
            di[r - c + N - 1] = true;
            select(b + 1, cnt + 1);
            di[r - c + N - 1] = false;
        }
    }
}

int main(){
    // time_t start = time(NULL);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    possible.resize(N);
    for(auto & vec : possible){
        vec.resize(N);
        for(auto & ele : vec) cin >> ele;
    }
    di.assign(2 * N - 1, false);
    select(0, 0);
    cout << ans;
    // time_t end = time(NULL);
    // double duration = (double)(end - start);
    // cout << duration << "\n";
    return 0;
}