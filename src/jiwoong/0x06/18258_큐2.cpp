#include <iostream>
#include <string>
using namespace std;
#define MAXSIZE 5

template <typename T>
class Queue{
private:
    T* data;
    int tail;
    int head;
public:
    Queue(int maxSize = MAXSIZE):data(new T[maxSize]){
        tail = 1;
        head = 0;
    }
    void push(T data_){
        if (head == tail){
            return ;
        }else{
            data[tail] = data_;
            tail = (tail + 1) % MAXSIZE;
        }
    }
    void pop(){
        head = (head + 1) % MAXSIZE;
    }
    int size(){
        if (tail > head)
            return (tail - head - 1);
        else
            return (MAXSIZE - 1 - (head - tail));
    }
    void print(){
        cout << head << " " << tail << endl;
        for (int i = (head + 1) % MAXSIZE; i != tail ; i = (i + 1) % MAXSIZE)
            cout << data[i] << " ";
        cout << endl;
    }
    bool empty(){
        return ((head + 1) % MAXSIZE == tail);
    }
    T front(){
        return data[(head + 1) % MAXSIZE];
    }
    T back(){
        if (tail - 1 < 0)
            return data[MAXSIZE - 1];
        return data[tail - 1];
    }
    ~Queue(){
        delete [] data;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Queue<int> q;
    int N;
    cin >> N;
    q.print();
    while(N--){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int ipt;
            cin >> ipt;
            q.push(ipt);
        }else if(cmd == "front"){
            if (!q.empty())
                cout << q.front() << "\n";
            else
                cout << "-1\n";
        }else if(cmd == "back"){
            if (!q.empty())
                cout << q.back() << "\n";
            else
                cout << "-1\n";
        }else if (cmd =="pop"){
            if (!q.empty()){
                cout << q.front() << "\n";
                q.pop();
            }
            else
                cout << "-1\n";
        }else if(cmd == "empty"){
            cout << q.empty() << "\n";
        }else if(cmd == "size"){
            cout << q.size() << "\n";
        }
        q.print();
    }
    return 0;
}