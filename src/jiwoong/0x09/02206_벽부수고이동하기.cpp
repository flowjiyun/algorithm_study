#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
vector<string> map;
vector<vector<vector<int>>> visited;
queue<tuple<int,int,int>> q;

int dr[] = {-1, 0, +1, 0, -1, 0, +1, 0};
int dc[] = {0, +1, 0, -1, 0, +1, 0, -1};
int br[] = {0, 0, 0, 0, +1, +1, +1, +1};

bool isValid(int nr, int nc, int nb, int br){
    if(nr < 0 || nr >= N
     ||nc < 0 || nc >= M) return false;
    return (map[nr][nc] == br + '0' && visited[nb][nr][nc] == -1);
}

int main(){
    int r, c, b;
    int ans = -1;
    cin >> N >> M;
    map.resize(N);
    for(auto & str : map) cin >> str;
    visited.resize(2);
    for(auto & board : visited) {
        board.resize(N);
        for(auto & vec : board)
            vec.assign(M, -1);
    }
    q.push(make_tuple(0, 0, 0));
    visited[0][0][0] = 1;
    while(!q.empty()){
        tie(r, c, b) = q.front();
        q.pop();
        // for(auto & layer : visited){
        //     for(auto & row : layer){
        //         for(auto & ele : row){
        //             cout << ele << " ";
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }

        if (r == N - 1 && c == M - 1){
            ans = visited[b][r][c];
            break;
        }
        for(int d = 0 ; d < 4 * (2 - b) ; d++){
            int nr = r + dr[d], nc = c + dc[d], nb = b + br[d];
            if(isValid(nr, nc, nb, br[d])){
                q.push(make_tuple(nr, nc, nb));
                visited[nb][nr][nc] = visited[b][r][c] + 1;
            }
        }
    }
    cout << ans;
    return 0;
}