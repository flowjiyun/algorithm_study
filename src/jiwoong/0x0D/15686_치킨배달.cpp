#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;
// 2*(N - 1) * 2500 = 5000 * 50
int N, M, ans = 1250001;
vector<pair<int, int>> houses;
vector<pair<int, int>> stores;
vector<vector<int>> dist;
vector<int> selected;

void select(int start, int depth){
    if(depth >= M){
        int sum = 0;
        for(int h = 0 ; h < houses.size(); h++){
            int m = 100;
            for(auto & idx : selected){
                m = min(m, dist[h][idx]);
            }
            // cout << h << " : " << m << "\n";
            sum += m;
        }
        ans = min(ans, sum);
        return;
    }
    for(int i = start ; i < stores.size() ; i++){
        selected[depth] = i;
        select(i + 1, depth + 1);
    }
}

int main(){
    int H = 0, S = 0, d = 0;
    cin >> N >> M;
    houses.resize(2*N);
    stores.resize(13);
    selected.resize(M);
    for(int r = 0 ; r < N ; r++){
        for(int c = 0; c < N ; c++){
            int ipt;
            cin >> ipt;
            if(ipt == 1){
                houses[H++] = make_pair(r, c);
            }else if(ipt == 2){
                stores[S++] = make_pair(r, c);
            }
        }
    }
    houses.resize(H);
    stores.resize(S);
    // cout << "House : \n";
    // for(auto & house : houses) cout << "( " << house.first << " , " << house.second << " )\n";
    // cout << "Store : \n";
    // for(auto & store : stores) cout << "( " << store.first << " , " << store.second << " )\n";
    dist.resize(H);
    for(auto & vec : dist) vec.resize(S);
    for(int h = 0 ; h < H ; h++){
        for(int s = 0 ; s < S; s++){
            dist[h][s] = abs(houses[h].first - stores[s].first) + abs(houses[h].second - stores[s].second);
        }
    }
    // cout << "Dist : \n";
    // for(int h = 0; h < H; h++){
    //     for(int s = 0 ; s < S; s++){
    //         cout << dist[h][s] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    select(0, 0);
    cout << ans;

    return 0;
}