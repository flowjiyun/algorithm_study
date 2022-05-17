#include <vector>
#include <iostream>

using namespace std;

void swap3(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void func1(vector<int> v) {
    v[10] = 7;
}

bool comp1(vector<int> v1, vector<int> v2, int idx) {
/*
 v1, v2의 크기가 N일때, 이 함수의 시간복잡도: O(N)
 v1, v2를 인자로 보낼때 복사본을 만들어서 보낸다. 이때
 N개의 원소들을 하나하나 복사하는 과정으로 O(N)이 된다.
*/
    return v1[idx] > v2[idx];
}

bool comp2(vector<int> &v1, vector<int> &v2, int idx) {
/*
    v1, v2의 type이 vector reference이므로 이 함수의 시간 복잡도: O(1)
*/
    return v1[idx] > v2[idx];
}

int main() {
    vector<int> v(100);
    func1(v);
    cout << v[10];

    return (0);
}