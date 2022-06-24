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
        sort(s, mid);
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
        for(int i = left ; i <= right ; i++){
            while(vec[i] <= pivot){
                swap(vec[i], vec[right]);
                if(vec[right] != pivot){
                    right--;
                }
                if(right == i) break;
            }
        }
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