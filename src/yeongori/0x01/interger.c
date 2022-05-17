int main()
{
    int a = 1;
    int mod = 1000000007;
    for (int i = 0; i < 10; i++) {
        a = 10 * a % mod;
    }
    // OVERFLOW!!
    return (a);
}