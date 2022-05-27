#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;
    int N;
    cin >> N;
    while(N--){
        int ipt;
        cin >> ipt;
        if (ipt == 0){
            s.pop();
        }else{
            s.push(ipt);
        }
    }
    long long sum = 0;
    while (!s.empty()){
        sum += s.top();
        s.pop();
    }
    cout << sum;
    return 0;
}