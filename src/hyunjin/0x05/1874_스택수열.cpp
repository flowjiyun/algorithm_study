#include <bits/stdc++.h>
using namespace std;

stack<int> s;
int n, num, sign;
int arr[100000];
char output[2000000];

int run()
{
    int t = 1;
    
    for (int k = 0; k < n; k++){
        int flag = 0;

        if (s.empty()) {
            s.push(t++);
            output[sign++] = '+';
        }

        if (arr[k] > s.top()){
            while (arr[k] > s.top()){
                s.push(t++);
                output[sign++] = '+';
            }
        }
        else if (arr[k] < s.top()) {
            return (1);
        }

        if (arr[k] == s.top()) {
            s.pop();
            output[sign++] = '-';
        }
    }
    return (0);
}


int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    if (run() == 1) cout << "NO";
    else {
        for (int i = 0; i < sign; i++){
            cout << output[i] << "\n";
        }
    }
}
