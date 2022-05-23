#include <iostream>
using namespace std;

int cards[21];

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void change(int start, int end){
    for(int i = start; i < (start + end + 1)/2 ; i++)
        swap(cards[i], cards[end - i + start]);
}
int main()
{
    for (int i = 1 ; i <= 20 ; i++){
        cards[i] = i;
    }
    int T = 10;
    while (T--){
        int s, e;
        cin >> s >> e;
        change(s, e);
    }
    for (int i = 1 ; i <= 20 ; i++){
        cout << cards[i] << " ";
    }
    return 0;
}