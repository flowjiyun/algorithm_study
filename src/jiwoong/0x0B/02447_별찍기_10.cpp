#include <iostream>
#include <vector>
#include <string>
// 3^14 : 4782969 보관 가능
using namespace std;

int N;
vector<string> ans;
void divide(const int& sr, const int& sc, const int& size, const int& id){
    int d = 1;
    if (id == 5) return;
    if(size == 1){
        ans[sr][sc] = '*';
        return;
    }
    for(int r = sr; r < sr + size; r += size / 3){
        for(int c = sc ; c < sc + size ; c += size /3){
            divide(r, c, size / 3, d++);
        }
    }
}

int main(){
    cin >> N;
    ans.resize(N);
    for(auto & str: ans) str.assign(N, ' ');
    divide(0, 0, N, 1);
    for(auto & str: ans){
        cout << str << "\n";
    }
    return 0;
}