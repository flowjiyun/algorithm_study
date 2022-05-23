#include <iostream>
#include <list>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        list<char> editor;
        list<char>::iterator cursor;
        editor.push_back('\0');
        cursor = editor.begin();
        string cmd;
        cin >> cmd;
        for(auto& c: cmd){
            switch(c){
                case '<':
                    if(cursor != editor.begin())
                    cursor--;
                    break;
                case '>':
                    if(cursor != --editor.end())
                    cursor++;
                    break;
                case '-':
                    if(cursor != editor.begin()){
                        cursor = editor.erase(--cursor);
                        // cursor++;
                    }
                    break;
                default:
                    cursor = editor.insert(cursor,c);
                    cursor++;
                    break;
            }
            // for (list<char>::iterator it = editor.begin() ; it != editor.end(); it++){
            //     if (it == cursor){
            //         cout << '[';
            //         cout << *it;
            //         cout << ']';
            //     }
            //     else
            //         cout <<*it;
            // }
            // cout << endl;

        }
        for (auto& ele : editor){
            if(ele == '\0') break;
            cout <<ele;
        }
        // for(list<char>::iterator it = editor.begin(); ; it++){
        //     if(++it == editor.end())
        //         break;
        //     cout<<*it;
        // }
        cout << "\n";
    }
    return 0;
}