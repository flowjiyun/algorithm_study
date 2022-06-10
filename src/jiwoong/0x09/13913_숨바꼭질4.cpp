#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int pl(int i) {return i + 1;}
int mi(int i) {return i - 1;}
int duplicate(int i) {return 2 * i;}

int N, K;
int (*f[3])(int);
vector<int> space;
vector<int> pre;

bool isValid(int n){
    if(n < 0 || n > 100000) return false;
    return (space[n] == -1);
}

void print(int p){
    if(pre[p] == -1){
        cout << p << " ";
        return;
    }
    print(pre[p]);
    cout << p << " ";
}

int main(){
    f[0] = duplicate;
    f[1] = pl;
    f[2] = mi;
    cin >> N >> K;
    space.assign(100001, -1);
    pre.assign(100001, -1);
    queue<int> q;
    q.push(N);
    space[N] = 0;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        if (cur == K) break;
        for(auto &fun : f){
            if(isValid(fun(cur))){
                q.push(fun(cur));
                space[fun(cur)] = space[cur] + 1;
                pre[fun(cur)] = cur;
            }
        }
    }
    cout << space[K] << "\n";
    print(K);
    return 0;
}