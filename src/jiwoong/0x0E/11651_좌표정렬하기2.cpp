#include <iostream>
#include <vector>

using namespace std;
pair<int, int> vec[1000001];
pair<int, int> newArr[1000001];
int N;

void swap(int & a, int & b){
    int temp = a;
    a = b;
    b = temp;
}

bool compare(pair<int, int> & p1, pair<int, int> & p2){
    if(p1.second < p2.second) return true;
    else if(p1.second > p2.second) return false;
    else{
        if(p1.first <= p2.first) return true;
        else return false;
    }
}

namespace merge{
    void sort(int s, int e){
        if(s >= e) return;
        int mid = (s + e)/2;
        sort(s, mid);
        sort(mid + 1, e);
        int left = s, right = mid + 1;
        for(int i = s ; i <= e; i++){
            if(left <= mid && compare(vec[left], vec[right])){
                newArr[i] = vec[left++];
            }else if(right <= e && compare(vec[right],vec[left])){
                newArr[i] = vec[right++];
            }else if(right > e) newArr[i] = vec[left++];
            else if(left > mid) newArr[i] = vec[right++];
        }
        for(int i = s; i <= e; i++){
            vec[i] = newArr[i];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    // select(0);
    for(int i = 0 ; i < N; i++) cin >> vec[i].first >> vec[i].second;
    merge::sort(0, N - 1);
    for(int i = 0 ; i < N; i++) cout << vec[i].first << " " << vec[i].second << "\n";
    return 0;
}