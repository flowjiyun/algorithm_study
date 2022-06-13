#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> map;
class TreeNode{
public:
    int id;
    TreeNode* children[4];
    TreeNode(){
        for(int d = 0 ; d < 4 ; d++) children[d] = nullptr;
    }
    ~TreeNode(){
        for(int d = 3 ; d >= 0 ;d--){
            delete children[d];
        }
    }
};

class Tree{
public:
    TreeNode *head;
    Tree(){
        head = nullptr;
    }
    void init(int sr, int sc, int size){
        head = build(sr, sc, size);
    }
    TreeNode* build(int sr, int sc, int size){
        int d = 0, newId;
        TreeNode *newNode = new TreeNode;
        if(size == 1){
            newNode->id = map[sr][sc] - '0';
            return newNode;
        }
        for(int r = sr; r < sr + size ; r += size / 2){
            for(int c = sc ; c < sc + size ; c += size / 2){
                newNode->children[d++] = build(r, c, size / 2);
            }
        }
        newId = newNode->children[0]->id;
        for(int i = 1 ; i < 4 && newId != -1; i++){
            if(newNode->children[i]->id == -1 || newId != newNode->children[i]->id) {
                newId = -1;
                break;
            }
        }
        newNode->id = newId;
        return newNode;
    }
    ~Tree(){
        if(head != nullptr) delete head;
    }
};

 void print(TreeNode*& readNode){
    if(readNode->id == -1){
        cout << "(";
        for(int d = 0 ; d < 4; d++){
            print(readNode->children[d]);
        }
        cout << ")";
    }else{
        cout << readNode->id;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Tree tree;
    int N;
    cin >> N;
    map.resize(N);
    for(auto & row : map){
        row.resize(N);
        for(auto & ele : row) cin >> ele;
    }
    tree.init(0, 0, N);

    print(tree.head);
    return 0;
}