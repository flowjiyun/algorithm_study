#include <iostream>
using namespace std;

void printSpace(int n){
    for(int i = 0 ; i < n ; i++)
        cout << " ";
}

void printStars(int n){
    for(int i = 0 ; i < n ; i++)
        cout << "*";
}

int main2440();
int main2441();
int main2443();
int main2444();
int main2445();

int main(){
    main2445();
    return 0;
}

int main2445(){
    int N;
    cin >> N;
    for(int i = 1 ; i <= 2*N - 1; i++){
        if(i <= N){
            printStars(i);
            printSpace(2 * N - 2 *i);
            printStars(i);
        }else{
            printStars(2 * N - i);
            printSpace(2 * i - 2 * N);
            printStars(2 * N - i);
        }
        cout << "\n";
    }
    return 0;
}

int main2444(){
    int N;
    cin >> N;
    for(int i = 1 ; i <= 2 * N - 1 ; i++){
        if (i <= N)
        {
            printSpace(N - i);
            printStars(2 * i - 1);
        }
        else
        {
            printSpace(i - N);
            printStars(2 * N - 1 - 2 * (i - N));
        }
        cout << "\n";
    }
    return 0;
}
int main2443(){
    int N;
    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        printSpace(i - 1);
        printStars(2 * (N - i + 1) - 1);
        cout << "\n";
    }
    return 0;
}
int main2441(){
    int N;
    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        printSpace(i - 1);
        printStars(N + 1 - i);
        cout << "\n";
    }
    return 0;
}
int main2440(){
    int N;
    cin >> N;
    for(int i = N ; i >= 1 ; i--){
        printStars(i);
        cout << "\n";
    }
    return 0;
}