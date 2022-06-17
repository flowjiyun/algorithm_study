#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
int ans = 0;
vector<int> num;

void select(int node,int len, int sum){
    if (node >= N) return;
    select(node + 1, len, sum);
    if (sum + num[node] == S){
        ans += 1;
    }
    select(node + 1, len + 1, sum + num[node]);
}

int main(){
    cin >> N >> S;
    num.resize(N);

    for(auto & ele: num) cin >> ele;
    select(0, 0, 0);
    cout << ans;
    return 0;
}