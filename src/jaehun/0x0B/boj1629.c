//곱셈

#include <stdio.h>

#define ll long long

ll recursive(ll a, ll b, ll c) {
    if (b == 1)
        return a%c;
    ll tmp=recursive(a, b/2, c);
    tmp = tmp * tmp % c;
    if (b%2 == 0)
        return tmp;
    if (b%2 == 1)
        return tmp * a % c;
}

int main() {
    ll a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", recursive(a, b, c));
}