#include <bits/stdc++.h>

using namespace std;

int FastPower(int x, int n)
{
    int result = 1;

    while (n > 0)
    {
        if (n & 1)
        {                // if the current bit is set
            result *= x; // multiply the result by x
        }
        x *= x;  // square the base
        n >>= 1; // divide the exponent by 2
    }

    return result;
}

int Modular_Exp(int base, int exp, int mod)
{
    int result = 1;

    while (exp > 0)
    {
        if (exp & 1)
        {
            result = ((result % mod) * (base % mod)) % mod; // multiply when the current bit is set
        }
        base = ((base % mod) * (base % mod)) % mod; // square the base
        exp >>= 1;                                  // divide the exponent by 2
    }

    return result;
}

// Problem given n , m find m mod 2 ^ n
// ranges 1<= n <= 1e8 1<=m <= 1e8
signed main()
{
    int n, m;
    cin >> n >> m;

    if (n >= 27)
    {
        cout << m << endl;
    }
    else
    {
        cout << m % FastPower(2, n) << endl;
    }
}
