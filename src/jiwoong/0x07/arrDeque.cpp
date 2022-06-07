#include <iostream>
using namespace std;

template <typename T>
class Deque{
private:
    T* data;
    int maxSize;
    int head;
    int tail;
    int size;
    int next(int cursor, int move = 1){
        return (cursor + move) % maxSize;
    }
    int prev(int cursor, int move = 1){
        if (cursor - move < 0)
            return maxSize - (move - cursor);
        else
            return cursor - move;
    }
public:
    Deque(int maxs = 10) : maxSize(maxs),head(maxSize - 1),tail(0){
        data = new T[maxSize];
    }
    void push_front(int data_){
        if(full()) return;
        size++;
        data[head] = data_;
        head = prev(head);
    }
    void push_back(int data_){
        if(full()) return;
        size++;
        data[tail] = data_;
        tail = next(tail);
    }
    void pop_front(){
        if(empty()) return;
        head = next(head);
        size--;
    }
    void pop_back(){
        if(empty()) return;
        tail = prev(tail);
        size--;
    }
    bool empty(){
        return (next(head) == tail);
    }
    bool full(){
        return (tail == head);
    }
    T front(){
        if(!empty())
            return data[next(head)];
        return -1;
    }
    T back(){
        if(!empty())
            return data[prev(tail)];
        return -1;
    }
    int getSize(){
        return size;
    }
    void print(){
        if(empty()) return;
        int temp = next(head);
        cout << "head : " << head << " tail : " << tail <<endl;
        for(; temp != tail ; temp = next(temp)){
            cout << data[temp] << " ";
        }
        cout << endl;
    }
    ~Deque(){
        delete [] data;
    }
};

int main(){
    Deque<int> dq(5);
    dq.print();
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.print();
    dq.pop_back();
    dq.print();
    dq.pop_back();
    dq.print();
    dq.pop_back();
    dq.print();
    dq.push_front(4);
    dq.push_front(5);
    dq.push_front(6);
    dq.push_front(7);
    dq.print();
    return 0;
}