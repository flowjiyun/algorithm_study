#include <iostream>
#include <list>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    list<int> l;
    list<int> ans;
    for(int i = 1 ; i <= N; i++){
        l.push_back(i);
    }
    int n = 0;
    while(!l.empty()){
        list<int>::iterator cur = l.begin();
        n = (n + K - 1) % l.size();
        advance(cur, n);
        // cout << *cur << endl;
        ans.push_back(*cur);
        l.erase(cur);
    }
    cout << "<";
    for(list<int>::iterator cur = ans.begin(); cur != ans.end() ; cur++){
        cout << *cur;
        if(cur != --ans.end())
            cout << ", ";
    }
    cout << ">";
    return 0;
}