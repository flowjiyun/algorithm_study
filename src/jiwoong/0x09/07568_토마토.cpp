#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <tuple>
using namespace std;
int dh[6] = {+1, -1, 0, 0, 0, 0};
int dn[6] = {0, 0, +1, 0 ,-1, 0};
int dm[6] = {0, 0, 0, +1, 0, -1};

int M, N, H;
vector<vector<vector<int>>> box;
queue<tuple<int ,int, int, int>> q;

bool isValid(int nh, int nn, int nm){
    if(nh < 0 || nh >= H) return false;
    if(nn < 0 || nn >= N) return false;
    if(nm < 0 || nm >= M) return false;
    if(box[nh][nn][nm] != 0) return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    bool suc = true;
    cin >> M >> N >> H;
    box.resize(H);
    for(auto & board : box){
        board.resize(N);
        for(auto & str : board){
            str.resize(M);
        }
    }
    for(int h = 0; h < H ; h++){
        for(int n = 0 ; n < N ; n++){
            for(int m = 0 ; m < M ;m++){
                cin >> box[h][n][m];
                if(box[h][n][m] == 1)
                    q.push(make_tuple(h, n , m, 1));
            }
        }
    }
    while(!q.empty()){
        int h, n, m, s;
        tie(h, n, m, s) = q.front();
        q.pop();
        for(int d = 0 ; d < 6 ;d++){
            int nh = h + dh[d], nn = n + dn[d], nm = m + dm[d];
            if(isValid(nh, nn, nm)){
                q.push(make_tuple(nh,nn,nm,s+1));
                box[nh][nn][nm] = s + 1;
            }
        }
    }
    for(auto & board : box){
        for(auto & str: board){
            for(auto & num: str){
                if(num == 0){
                    suc = false;
                    break;
                }else if(num == -1) continue;
                else{
                    ans = (ans < num) ? num : ans;
                }
            }
        }
    }

    // for(auto & board : box){
    //     for(auto & str: board){
    //         for(auto & num: str){
    //             cout << num << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    if(!suc) cout << -1;
    else cout << ans - 1;
    return 0;
}