#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> weight;
vector<int> armor;
int N;
int ans = 0;
void hit(int thrower){
    if(thrower == N){
        int cnt = 0;
        for(auto& a : armor){
            cnt += (a <= 0);
        }
        // cout << cnt << endl;
        ans = max(ans, cnt);
        return;
    }
    // for(auto& a : armor){
    //     cout << a << " ";
    // }
    if(armor[thrower] > 0){
        bool canHit = false;
        for(int c = 0; c < N ; c++){
            if(armor[c] > 0 && c != thrower){
                canHit = true;
                armor[thrower] -= weight[c];
                armor[c] -= weight[thrower];
                hit(thrower + 1);
                armor[thrower] += weight[c];
                armor[c] += weight[thrower];
            }
        }
        if(!canHit) hit(thrower + 1);
    }
    else hit(thrower + 1);
}

int main(){
    cin >> N;
    weight.resize(N);
    armor.resize(N);
    for(int i = 0; i < N ;i++){
        cin >> armor[i];
        cin >> weight[i];
    }
    hit(0);
    cout << ans;
    return 0;
}