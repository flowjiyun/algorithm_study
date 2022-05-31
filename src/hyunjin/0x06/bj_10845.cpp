#include <iostream>
using namespace std;
int arr[100000];

int main()
{
    int n;
    cin >> n;

    string order;
    int num;
    int head = 0;
    int tail = 0;
    for (int i = 0; i < n; i++) {
        cin >> order;

        if (order == "push") {
            cin >> num;
            arr[tail++] = num;
        }
        else if (order == "pop") {
            if (head  == tail) cout << -1 << "\n";
            else cout << arr[head++] << "\n";
        }
        else if (order == "size") {
            cout << tail - head << "\n";
        }
        else if (order == "empty") {
            if (tail == head) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (order == "front") {
            if (tail == head) cout << -1 << "\n";
            else cout << arr[head] << "\n";
        }
        else if (order == "back") {
            if (tail == head) cout << -1 << "\n";
            else cout << arr[tail - 1] << "\n";
        }
    }
}
