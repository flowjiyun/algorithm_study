#include <iostream>
#include <vector>
using namespace std;

int A, B, C;
vector<int> ans;
int cnt = 0;
void build(int b, int cur){
    if(ans[cur] != -1){
        return;
    }
    if(b == 1){
        ans[cur] = A % C;
        return;
    }
    build(b / 2, cur + 1);
    unsigned long long val = ans[cur + 1] % C;
    unsigned long long tmp = (val * val) % C;
    if(b % 2 == 0){
        ans[cur] = tmp;
    }else{
        ans[cur] = (tmp * (A % C)) % C;
    }
}

int main(){
    ans.assign(33, -1);
    cin >> A >> B >> C;
    build(B, 0);
    cout << ans[0];
    return 0;
}