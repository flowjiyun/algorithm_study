#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
vector<string> map;

void draw(int sr, int sc, int size){
    if(size == 3){
        for(int r = 0 ; r < 3; r++){
            for(int c = r ; c >= 0 ; c--){
                if(r == 1 && c == 0) continue;
                map[sr + r][sc + c] = '*';
                map[sr + r][sc - c] = '*';
            }
        }
        return;
    }
    draw(sr, sc, size / 2);
    draw(sr + size / 2, sc - size / 2, size / 2);
    draw(sr + size / 2, sc + size / 2, size / 2);
}
int main(){
    cin >> N;
    map.resize(N);
    for(auto & str : map){
        str.assign(2 * N, ' ');
    }
    draw(0, N , N);
    for(auto & str : map){
        for(int i = 1; i < str.length(); i++)
            cout << str[i];
        cout << "\n";
    }
    return 0;
}