#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>


#define Matrix vector<vector<int>>
#define Cube vector<Matrix> 
#define INIT 2
using namespace std;
vector<vector<vector<int>>> cube(5);
vector<int> seq(5, -1);
vector<bool> isVisited(5, false);

int dr[] = {-1, 0, +1, 0, 0, 0};
int dc[] = {0, +1, 0, -1, 0, 0};
int dh[] = {0, 0, 0, 0, +1, -1};
int ans = -1;
void swap(int & a, int & b){
    int temp = a;
    a = b;
    b = temp;
}

bool isInside(int nr, int nc, int nh){
    if(nr < 0 || nr >= 5 || nc < 0 || nc >= 5 |
       nh < 0 || nh >= 5) return false;
    return true;
}

void turnClockwise(Matrix& matrix, int size){
    for(int r = 0 ; r < size; r++){
        for(int c = 0 ; c < size - 1 - r; c++){
            swap(matrix[r][c], matrix[size - 1 -c][size - 1 - r]);
        }
    }
    for(int r = 0 ; r < size / 2 ; r++){
        for(int c = 0 ; c < size ; c++){
            swap(matrix[r][c], matrix[size - 1 -r][c]);
        }
    }
}

void bfs(int row, int col, int height, Cube & test){
    int step = -1;
    Cube temp(test);
    queue<tuple<int, int, int>> q;
    if(temp[row][col][height] == 1 && temp[4 - row][4 - col][4 - height] == 1){
        int r, c, h;
        q.push(make_tuple(row, col, height));
        temp[row][col][height] = INIT;
        while(!q.empty()){
            tie(r, c, h) = q.front();
            q.pop();
            if(r == 4 - row && c == 4 - col && h == 4 - height){
                step = temp[r][c][h];
                break;
            }
            for(int d = 0 ; d < 6; d++){
                int nr = r + dr[d], nc = c+ dc[d], nh = h + dh[d];
                if(isInside(nr, nc, nh) && temp[nr][nc][nh] == 1){
                    temp[nr][nc][nh] = temp[r][c][h] + 1;
                    q.push(make_tuple(nr, nc, nh));
                }
            }
        }
        if(step != -1){
            if(ans == -1) ans = step - INIT;
            else ans = min(ans, step - INIT);
        }
    }
}
// n 번째 matrix 돌리기
void rotateMatrix(int n, Cube & test){
    if(n >= 5){
        // cout << n << "\n";
        bfs(0, 0, 0, test);
        return;
    }
    // cout << "rotate : "<< n << "\n";
    for(int i = 0 ; i < 4; i++){
        rotateMatrix(n + 1, test);
        turnClockwise(test[n], 5);
    }
}

void select(int depth){
    if(depth >= 5){
        Cube test(5);
        for(int i = 0 ; i < 5; i++){
            test[i] = cube[seq[i]];
        }
        rotateMatrix(0, test);
        // seq 0 1 2 3 4
        //  ex 3 4 1 2 0

    }
    for(int i = 0 ; i < 5; i++){
        if(!isVisited[i]){
            seq[depth] = i;
            isVisited[i] = true;
            select(depth + 1);
            isVisited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cube.assign(5, vector<vector<int>>(5, vector<int>(5)));
    for(auto & matrix : cube){
        for(auto & vec : matrix){
            for(auto & ele : vec) cin >> ele;
        }
    }
    select(0);
    cout << ans;

    return 0;
}