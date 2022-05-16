#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int height[9];
vector<int> selected;

int    select(int start, int depth, int toFind){
    if (depth == 2){
        int sum = 0;
        for (auto ele : selected){
            sum += height[ele];    
        }
        if (sum == toFind)
            return 1;
        else
            return 0; 
    }
    for (int i = start ; i < 9; i++){
        selected.push_back(i);
        if (select(i + 1, depth + 1, toFind))
            return 1;
        selected.pop_back();
    }
    return 0;
}

int main(){
    int T = 9;
    int sum = 0;
    while (T--){
        cin >> height[T];
        sum += height[T];
    }
    sort(height, height + 9);
    sum -= 100;
    select(0, 0, sum);
    int it = 0;
    for (int i = 0 ; i < 9; i++){
        if (i == selected[it]){
            it++;
            continue;
        }
        cout << height[i] << "\n";
    }
    return 0;
}