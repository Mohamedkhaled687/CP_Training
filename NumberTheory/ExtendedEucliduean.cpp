#include <bits/stdc++.h>

using namespace std;

/* Theory
   The Extended Euclidean Algorithm computes the greatest common divisor (GCD) of two integers a and b,
   as well as the coefficients x and y such that ax + by = gcd(a, b).
   This is useful for solving linear Diophantine equations and finding modular inverses.


   Equations :
   ax + by = gcd(a, b) ---> 1

   bx1 + (a % b) * y1 = gcd(a, b) ---> 2

   bx1 + (a - b * floor(a/b)) * y1 = gcd(a, b) ---> 3

   ay1 + b * (x1 - floor(a/b)) = gcd(a, b) ---> 4

   from this equation, we can derive the values of x and y using back substitution.
   Complexity is O(log(min(a, b)))

*/

int extended_euclidean(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

signed main()
{
    int a, b;
    cin >> a >> b;

    int x, y;
    int gcd = extended_euclidean(a, b, x, y);
    cout << "GCD: " << gcd << endl;
    cout << "Coefficients: x = " << x << ", y = " << y << endl;
}