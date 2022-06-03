#include <iostream>
#include <list>
#include <string>
#include <utility>
using namespace std;

list<char> li;
void print(const list<char>::iterator cur, list<char>::iterator next){
    auto i = li.begin();
    while(i!=li.end()){
        if (i == cur){
            cout << "[ ";
        }
        cout << *i;
        if (i == next){
            cout << " ] ";
        }
        i++;
    }
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        string ipt;
        cin >> ipt;
        for(char ch : ipt){
            li.push_back(ch);
        }
        auto cur = li.begin();
        auto nxt = li.begin();
        if(!li.empty()){
            advance(nxt, +1);
        }
        while(!li.empty() && nxt != li.end()){
            // print(cur,nxt);
            if(*cur == '(' && *nxt == ')'){
                nxt = li.erase(nxt);
                cur = li.erase(cur);
                if (cur != li.begin()){
                    advance(cur, -1);
                }else{
                    advance(nxt, +1);
                }
            }else{
                advance(cur, +1);
                advance(nxt, +1);
            }
        }
        if(!li.empty()) cout << "NO\n";
        else cout << "YES\n";
        li.clear();
    }

    return 0;
}