#include <iostream>
#include <string>
using namespace std;
#define MAXSIZE 2000001

template <typename T>
class Queue{
private:
    T* data;
    int back_;
    int front_;
public:
    Queue(int maxSize = MAXSIZE):data(new T[maxSize]){
        back_ = 0;
        front_ = 0;
    }
    void push(T data_){
        if (front_ == back_ + 1){
            return ;
        }else{
            data[back_] = data_;
            back_ = (back_ + 1) % MAXSIZE;
        }
    }
    void pop(){
        front_ = (front_ + 1) % MAXSIZE;
    }
    int size(){
        if (back_ >= front_)
            return (back_ - front_);
        else
            return (MAXSIZE - (front_ - back_ - 1));
    }
    void print(){
        cout << back_ << " " << front_ << endl;
        for (int i = front_ ; i < back_ ; i++)
            cout << data[i] << " ";
        cout << endl;
    }
    bool empty(){
        return (back_ == front_);
    }
    T front(){
        return data[front_];
    }
    T back(){
        return data[back_ - 1];
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
    // q.print();
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
        // q.print();
    }
    return 0;
}