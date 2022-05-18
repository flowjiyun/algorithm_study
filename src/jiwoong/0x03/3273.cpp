#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int binarySearch(int start, int end , int target){
    if(start > end)
        return 0;
    int mid = (start + end) / 2;
        // cout << arr[mid] << "\n";
    if(arr[mid] == target){
        return 1;
    }
    else if(arr[mid] > target)
        return binarySearch(start, mid - 1, target);
    else
        return binarySearch(mid + 1, end, target);
}

int main(){
    int N, X, ans;
    cin >> N;
    for(int i = 0 ; i < N; i++)
        cin >> arr[i];
    cin >> X;
    sort(arr, arr + N);
    ans = 0;
    for (int i = 0 ; i < N; i++){
        // cout << "searching " << arr[i] << "\n";
        ans += binarySearch(i + 1, N - 1, X - arr[i]);
    }
    cout << ans;
    return 0;
}