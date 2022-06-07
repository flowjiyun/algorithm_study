#include <iostream>
using namespace std;

class Queue;

class Node{
private:
    int data;
    Node *prev;
public:
    Node(int d = 0, Node *p = NULL) : data(d), prev(p){}
    friend class Queue;
};

class Queue{
private:
    Node *head;
    Node *tail;
    int size;
public:
    Queue():size(0){
        head = NULL;
        tail = NULL;
    }
    void push(int data_){
        Node *newNode = new Node(data_, NULL);
        size++;
        if (head == NULL){
            head = tail = newNode;
        }else{
            tail->prev = newNode;
            tail = newNode;
        }
    }
    void pop(){
        if (head == NULL)   return;
        Node *temp = head;
        head = head->prev;
        if (head == NULL)
            tail = NULL;
        delete temp;
        size--;
    }
    void print(){
        Node *temp = head;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
    ~Queue(){
        while(head != NULL){
            Node *temp = head;
            head = head -> prev;
            delete temp;
        }
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.print();
    q.pop();
    q.print();
    return 0;
}