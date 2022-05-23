#include <iostream>
#include <string>
using namespace std;

class Editor;

class Node{
private:
    char data;
    Node* next;
    Node* prev;
public:
    Node(char data_ = '\0'):data(data_),next(NULL),prev(NULL){}
    ~Node(){}
    void setNext(Node* next_) {next = next_;}
    void setPrev(Node* prev_) {prev = prev_;}

    friend Editor;
};

class Editor{
private:
    Node *head;
    Node *cursor;
public:
    Editor():head(new Node),cursor(head){}
    void moveLeft(){
        if(cursor->prev != NULL)
            cursor = cursor->prev;
    }

    void moveRight(){
        if(cursor->next != NULL)
            cursor = cursor->next;
    }

    void pushNode(char c){
        Node *newNode = new Node(c);
        newNode->next = cursor;
        newNode->prev = cursor->prev;
        if(cursor == head) 
        {
            head = newNode;
        }
        else
            cursor->prev->next = newNode;
        cursor->prev = newNode;
    }

    void deleteNode(){
        if (cursor->prev == NULL)
            return;
        if (cursor->prev == head){
            head = cursor;
            delete cursor->prev;
            cursor->prev = NULL;
            return;
        }else{
            Node *temp = cursor->prev;
            cursor->prev->prev->next = cursor;
            cursor->prev = cursor->prev->prev;
            delete temp;
            return;
        }
    }
    void print(){
        Node* read = head;
        // cout << "cursor" << endl;
        // cout.width(16);
        // cout << cursor->prev << " ";
        // cout.width(16);
        // cout << cursor << " ";
        // cout.width(16);
        // cout << cursor->data << " ";
        // cout.width(16);
        // cout << cursor->next << " ";
        // cout << endl;
        while(read->next != NULL){
            // cout.width(16);
            // cout << read->prev << " ";
            // cout.width(16);
            // cout << read << " ";
            // cout.width(16);
            cout << read->data;
            // cout.width(16);
            // cout << read->next << " ";
            // cout << endl;
            read = read->next;
        }
    }
    ~Editor(){
        Node *cur = head;
        while (cur != NULL){
            Node *del = cur;
            cur = cur->next;
            delete del;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Editor editor;
    string str;
    cin >> str;
    for(int i = 0; str[i] != '\0';i++)
    {    
        editor.pushNode(str[i]);
        // editor.print();
        // cout << endl;
    }
    int T;
    cin >> T;
    while(T--){
        // editor.print();
        // cout << endl;
        char cmd;
        cin >> cmd;
        switch(cmd){
            case 'P':
                char ch;
                cin >> ch;
                editor.pushNode(ch);
                break;
            case 'L':
                editor.moveLeft();
                break;
            case 'D':
                editor.moveRight();
                break;
            case 'B':
                editor.deleteNode();
                break;
        }
    }
    editor.print();
    return 0;
}