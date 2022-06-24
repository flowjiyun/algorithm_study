#include <iostream>
#include <vector>

using namespace std;
int vec[1000001];
int newArr[1000001];
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
        // 0 ... 4 : mid 2
        // 0 ... 2
        sort(s, mid);
        // 3 ... 4
        sort(mid + 1, e);
        int left = s, right = mid + 1;
        for(int i = s ; i <= e; i++){
            if(left <= mid && vec[left] <= vec[right]){
                newArr[i] = vec[left++];
            }else if(right <= e && vec[right] < vec[left]){
                newArr[i] = vec[right++];
            }else if(right > e) newArr[i] = vec[left++];
            else if(left > mid) newArr[i] = vec[right++];
        }
        for(int i = s; i <= e; i++){
            vec[i] = newArr[i];
        }
    }
}

namespace quick{
    void sort(int s, int e){
        if(e - s <= 0) return;
        int pivot = vec[(s + e) / 2];
        int left = s, right = e;
        // [5 4 3 2 1] mid : 2 
        // cout << left << " " << right << "\n";


        // Sol1)
        // for(int i = left; i <= right ; i++){
        //     while(vec[i] > pivot){
        //         swap(vec[i], vec[right]);
        //         right--;
        //     }
        // } 

        // Sol2)
        // while(left < right){
        //     while(vec[left] < pivot) left++;
        //     while(vec[right] > pivot) right--;
        //     if(left < right){
        //         if(vec[left] == pivot && vec[right] == pivot){
        //             left++;
        //         }else{
        //             swap(vec[left], vec[right]);
        //             if(vec[left] != pivot) 
        //                 left++;    
        //             if(vec[right] != pivot)
        //                 right--;
        //         }
        //     }
        // }

        // Sol3)
        for(int i = left ; i <= right ; i++){
            while(vec[i] >= pivot){
                swap(vec[i], vec[right]);
                if(vec[right] != pivot){
                    right--;
                }
                if(right == i) break;
            }
        }
        // for(int j = 0 ; j < N ; j++){
        //     cout << vec[j] << " ";
        // }
        // cout << endl;
        // for(int j = 0 ; j < N ; j++){
        //     if(j == left && j == right) cout << "* ";
        //     else if(j == left ) cout << "^ ";
        //     else if(j == right) cout << "- ";
        //     else cout << "  ";
        // }
        // cout << endl;
        // usleep(300 * 1000);
        
        sort(s, right - 1);
        sort(right + 1, e);
    }
}

void select(int depth){
    if(depth == N){
        cout << "Before : ";
        for(int i = 0 ; i < N; i++) cout << vec[i] << " ";
        cout << endl;
        quick::sort(0, N - 1);
        cout << "After  : ";
        for(int i = 0 ; i < N; i++) cout << vec[i] << " ";
        cout << endl;
        usleep(300 * 1000);
    }
    for(int i = 0; i <= 9 ; i++){
        vec[depth] = i;
        select(depth + 1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    // select(0);
    for(int i = 0 ; i < N; i++) cin >> vec[i];
    quick::sort(0, N - 1);
    for(int i = 0 ; i < N; i++) cout << vec[i] << "\n";
    return 0;
}