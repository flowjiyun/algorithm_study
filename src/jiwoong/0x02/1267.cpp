#include <iostream>
#include <algorithm>
using namespace std;

int costs[10001];

int costSum(const int& crit_, const int& N, const int &price_){
    int criterion = crit_;
    int price = price_;
    int sum = 0;
    for (int i = 0 ; i < N ; i++){
        while (costs[i] >= criterion){
            criterion += crit_;
            price += price_;
        }
        sum += price;
    }
    return sum;
}

int main(){
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> costs[i];
    }
    sort(costs, costs + N);
    int Y = costSum(30, N, 10);
    int M = costSum(60, N, 15);
    if (Y > M){
        cout << "M "<< M << "\n";
    }else if(Y < M){
        cout << "Y "<< Y << "\n";
    }else
        cout << "Y M "<< Y << "\n";
    return 0;
}