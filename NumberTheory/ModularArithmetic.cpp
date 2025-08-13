#include <bits/stdc++.h>
using namespace std;

/***************************************** Modular Arithmetic *****************************************/
/*
Some properties :
* negative numbers are handled by adding the modulus ex : -8 % 3 = (-8%3 + 3) % 3 = 1
* (a + b) mod m = ((a mod m) + (b mod m)) mod m
* (a * b) mod m = ((a mod m) * (b mod m)) mod m
* (a - b) mod m = ((a mod m) - (b mod m) + m) mod m
* (a / b) mod m = ((a mod m) * (b^(-1) mod m)) mod m
*/

// Problem :
// Given two number a , b find the last digit of b!/a!

#define int long long

signed main()
{
    int a, b;
    cin >> a >> b;

    if (a == b)
    {
        cout << 1 << endl;
    }
    else if (b - a >= 10)
    {
        cout << 0 << endl;
    }
    else
    {
        int result = 1;

        for (int i = a + 1; i <= b; i++)
        {
            result *= (i % 10);
        }
        cout << result % 10 << endl; // last digit of the product
    }
}