#include <iostream>
#include <vector>
#include <string>
using namespace std;
pair<int, string> vec[1000001];
pair<int, string> newArr[1000001];
int N;

void swap(int & a, int & b){
    int temp = a;
    a = b;
    b = temp;
}
namespace merge{
    void sort(int s, int e){
        if(s >= e) return;
        int mid = (s + e)/2;
        sort(s, mid);
        sort(mid + 1, e);
        int left = s, right = mid + 1;
        for(int i = s ; i <= e; i++){
            if(left <= mid && vec[left].first <= vec[right].first){
                newArr[i] = vec[left++];
            }else if(right <= e && vec[right].first < vec[left].first){
                newArr[i] = vec[right++];
            }
            else if(left > mid) newArr[i] = vec[right++];
            else if(right > e) newArr[i] = vec[left++];
        }
        for(int i = s; i <= e; i++){
            vec[i] = newArr[i];
        }
    }
}

// namespace quick{
//     void sort(int s, int e){
//         if(e - s <= 0) return;
//         int pivot = vec[(s + e) / 2];
//         int left = s, right = e;
//         for(int i = left ; i <= right ; i++){
//             while(vec[i] <= pivot){
//                 swap(vec[i], vec[right]);
//                 if(vec[right] != pivot){
//                     right--;
//                 }
//                 if(right == i) break;
//             }
//         }
//         sort(s, right - 1);
//         sort(right + 1, e);
//     }
// }

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