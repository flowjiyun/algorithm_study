#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
using namespace std;
#define Pos pair<int, int>
#define ROW first
#define COL second
int N, M;

ostream& operator<<(ostream& out, const Pos& p){
    out << "( " << p.ROW << " , " << p.COL << " )";
    return out;
}

void printMap(const vector<string> & map){
    for(auto & str : map){
        cout << str << "\n";
    }
    cout << "\n";
}


// 아 오 위 왼
int dr[] = {+1, 0, -1, 0};
int dc[] = {0 ,+1, 0, -1};
int ir[4];
int ic[4];
Pos target;
vector<string> original;

bool isPassed(const vector<string>& temp, Pos cur, int direction){
    if(direction < 2) direction += 2;
    else direction -= 2;

    for(int step = 0 ; step < N - 1; step++){
        int row = cur.ROW + step * dr[direction] , col = cur.COL + step * dc[direction];
        if(row < 1 || row >= N - 1 || col < 1 || col >= M - 1) return false;
        if(temp[row][col] == '#') return false;
        if(Pos(row,col) == target) return true;
    }
    return false;
}

class Board{
public:
    vector<string> map;
    Pos red;
    Pos blue;
    int dist;
    Board(const vector<string> & ori, const Pos& r, const Pos &b)
    :map(ori), red(r), blue(b){
        dist = 0;
    }
};

int main(){
    int ans = -1;
    Pos red, blue;
    bool isFinish = false;
    queue<Board> q;
    cin >> N >> M;
    /*
        아래로 기울일 때
        (dr, x) : 
        오른쪽 기울일 때
        (x, dc)
        위로   기울일 떄
        (N - 1 + dr, x)
        왼쪽   기울일 때
        (x , M - 1 + dc)
    */
    ir[0] = ir[1] = ir[3] = 0;
    ic[0] = ic[1] = ic[2] = 0;
    ir[2] = N - 1;
    ic[3] = M - 1;
    original.resize(N);
    for(auto & str : original) cin >> str;
    for(int r = 0 ; r < N ; r++){
        for(int c = 0 ; c < M; c++){
            switch(original[r][c]){
                case 'R':
                    red.ROW = r;
                    red.COL = c;
                    break;
                case 'B':
                    blue.ROW = r;
                    blue.COL = c;
                    break;
                case 'O':
                    target.ROW = r;
                    target.COL = c;
                    break;
                default:
                    break;
            }
        }
    }
    q.push(Board(original, red, blue));
    while(!q.empty() && !isFinish){
        Board cur = q.front();
        q.pop();
        if(cur.dist >= 10) continue;
        for(int d = 0 ; d < 4 && !isFinish; d++){
            bool isFail = false, redPassed = false;
            Board temp(cur);
            int length = M * (dr[d] != 0) + N * (dc[d] != 0);
            for(int x = 1; x < length - 1 && (!isFail && !isFinish); x++){
                stack<char> s;
                int len = M * (dc[d] != 0) + N * (dr[d] != 0);
                for(int step = 0; step < len ; step++){
                    int r = x * (dr[d] == 0) + ir[d] + step * dr[d];
                    int c = x * (dc[d] == 0) + ic[d] + step * dc[d];
                    if(target == Pos(r, c)){
                        if(!s.empty() && s.top() == 'R'){
                            temp.red = Pos(r, c);
                            redPassed = true;
                            s.pop();
                        }
                        if(!s.empty() && s.top() == 'B'){
                            temp.blue = Pos(r, c);
                            isFail = true;
                            break;
                        }
                        if(redPassed){
                            isFinish = true;
                            ans = temp.dist + 1;
                            break;
                        }
                    }
                    if(temp.map[r][c] != '.') s.push(temp.map[r][c]);
                }
                if(isFail || isFinish) break;
                for(int step = len - 1 ; step >= 0 ; step--){
                    int r = x * (dr[d] == 0) + ir[d] + step * dr[d];
                    int c = x * (dc[d] == 0) + ic[d] + step * dc[d];
                    if(temp.map[r][c] != '#'){
                        if(s.empty() || s.top() == '#') temp.map[r][c] = '.';
                        // 'R' or 'B'
                        else{
                            if(s.top() == 'R'){
                                temp.red.ROW = r, temp.red.COL = c;
                            }else{
                                temp.blue.ROW = r, temp.blue.COL = c;
                            }
                            temp.map[r][c] = s.top();
                            s.pop();
                        }
                    }else{
                        // 벽은 반드시 충분히 있음.
                        s.pop();
                    }
                }
            }
            // printMap(temp.map);
            temp.dist += 1;
            if(isFail) continue;
            if(isFinish) break;
            // Pos nxt(temp.blue.ROW + dr[d], temp.blue.COL + dc[d]);
            // if(isPassed(temp.map, temp.blue, d) || isPassed(temp.map, nxt, d)) continue;
            // if(isPassed(temp.map, temp.red, d)){ 
            //     ans = temp.dist;
            //     isFinish = true;
            //     break;
            // }
            if(cur.red == temp.red && cur.blue == temp.blue) continue;
            q.push(temp);
        }
    }
    cout << ans;
    return 0;
}