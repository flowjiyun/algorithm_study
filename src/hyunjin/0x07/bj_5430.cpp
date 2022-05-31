#include <bits/stdc++.h>
using namespace std;

int run(){
    deque<int> d;
    string func, arr;
    int n;

    cin >> func >> n >> arr;

    // atoi
    int k = n;
    int i = 0;
    while (k) {
        if ('0' > arr[i] || arr[i] > '9') {
            i++;
            continue;
        }

        int num = 0;
        while ('0' <= arr[i] && arr[i] <= '9') {
            num = 10 * num + arr[i++] - '0';
        }
        k--;
        d.push_back(num);
    }


    // order
    int len = func.length();
    int rev = 0;
    for (int i = 0; i < len; i++) {
        if (func[i] == 'R') {
            rev = 1 - rev;
        }
        else if (func[i] == 'D') {          
            if (d.empty()) return (1);
            if (!rev) d.pop_front();
            else d.pop_back();
        }
    }
    if (rev) reverse(d.begin(), d.end());
    

    // print
    cout << "[";
    while (!d.empty()) {
        cout << d.front();
        d.pop_front();
        if (!d.empty()) cout << ",";
    }
    cout << "]\n";
    return (0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    while (t--) {
        if (run() == 1) cout << "error\n";
    }
}
