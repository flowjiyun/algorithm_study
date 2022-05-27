#include <iostream>
#include <stack>
using namespace std;

int arr[100001];
char ans[100001];

int main(){
    int n, c = 0;
    bool suc = true;
    cin >> n;
    stack<int> s;
    s.push(0);
    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    int cur = 1;
    for(int i = 0 ; i < n ;i++){
        if (s.top() < arr[i]){
            while(cur <= arr[i]){
                s.push(cur++);
                ans[c++] = '+';
                // cout << "+\n";
            }
            if(s.top() == arr[i]){
                s.pop();
                ans[c++] = '-';
                // cout << "-\n";
            }else{
                suc = false;
                break;
            }
        }else if (s.top() > arr[i]){
            while(!s.empty() && s.top() >= arr[i]){
                s.pop();
                ans[c++] = '-';
                // cout << "-\n";
            }
            if(s.empty()){
                suc = false;
                break;
            }
        }else{
            s.pop();
            ans[c++] = '-';
        }
    }
    if(suc){
        for(int i = 0 ; i < c; i++){
            cout << ans[i] << "\n";
        }
    }else{
        cout << "NO\n";
    }
    return 0;
}