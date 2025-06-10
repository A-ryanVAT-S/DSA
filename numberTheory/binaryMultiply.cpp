// recurssive
int BexpRec(int a, int b)
{
    if (b == 0)
        return 1;
    long long x = BexpRec(a, b / 2);
    if (b % 2 == 0)
        return x * x;
    else
        return a * x * x;
}
// iterative
int BexpIter(int a, int b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}
// Mod exp(for large a(<10^18) and small m(<10^9))
int BexpMod(int a, int b, int m)
{
    long long res = 1;
    a = a % m;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

// for Large M(<10^18)
int binMultiply(int a, int b, long long m)
{
    long long res = 0;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res + a) % m;
        a = (a * 2) % m;
        b /= 2;
    }
    return res;
}

int BexpModLarge(int a, int b, long long m)
{
    long long res = 1;
    a = a % m;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = binMultiply(res, a, m);
        a = binMultiply(a, a, m);
        b /= 2;
    }
    return res;
}
// for large b(b raised to c)
int BexpModLargeB(int a, long long b, int m)
{
    long long res = 1;
    a = a % m;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = binMultiply(res, a, m);
        a = binMultiply(a, a, m);
        b /= 2;
    }
    return res;
}
while
passing in main
    pass
    BexpModLargeB(a, BexpModLargeB(b, c, m - 1), m)



//simple mod power fxn
ll modpow(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}
compute a^b with mod