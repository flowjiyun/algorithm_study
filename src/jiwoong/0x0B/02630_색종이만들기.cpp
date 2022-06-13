#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
vector<int> ans(2, 0);

int id(int *arr){
    int temp = arr[0];
    for(int i = 1; i < 4 && temp != -1; i++){
        if(temp != arr[i] || arr[i] == -1) return -1;
    }
    return temp;
}

int divide(int sr, int sc, int size){
    if(size == 1) return map[sr][sc];
    int temp[4] = {0, 0 ,0, 0}, d = 0, res;
    for(int r = sr; r < sr + size ; r += size / 2){
        for(int c = sc; c < sc + size ; c += size /2){
            temp[d++] = divide(r, c, size / 2);
        }
    }
    //conquer
    res = id(temp);
    if(res == -1){
        for(auto & ele: temp){
            if(ele == -1) continue;
            ans[ele] += 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    map.resize(N);
    for(auto & row : map){
        row.resize(N);
        for(auto & ele : row) cin >> ele;
    }
    int res = divide(0, 0, N);
    if(res != -1){
        ans[res] += 1;
    }
    for(auto & ele : ans){
        cout << ele << "\n";
    }
    return 0;
}