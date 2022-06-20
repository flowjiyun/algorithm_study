#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<int> seq;
vector<int> num;
map<int, int> cnt; // map <key, value> cnt... cnt[21억] => 21억 : 3
int N, M, R = 0;

void select(const int& start, const int& depth){
    if(depth > M){
        for(int i = 0 ; i < M ; i++){
            cout << seq[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = start; i < R; i++){
        if(cnt[num[i]] > 0){
            cnt[num[i]] -= 1;
            seq[depth - 1] = num[i];
            select(i ,depth + 1);
            cnt[num[i]] += 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    seq.resize(N);
    num.resize(N);
    for(int i = 0 ; i < N; i++){
        int ipt;
        bool isSame = false;
        cin >> ipt;
        for(int r = 0 ; r < R; r++){
            if(ipt == num[r]){
                isSame = true;
                break;
            }
        }
        if(!isSame) {
            num[R++] = ipt;
            cnt.insert(make_pair(ipt, 1));  // 리턴값 (  false)
        }else{
            cnt[ipt] += 1;
        }
    }
    num.resize(R);
    sort(num.begin(), num.end());
    select(0, 1);
    return 0;
}