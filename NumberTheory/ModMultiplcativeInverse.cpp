#include <bits/stdc++.h>
using namespace std;

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

int mod_Inverse(int A, int M)
{
    int x, y;
    int gcd = extended_euclidean(A, M, x, y);
    if (gcd != 1)
    { // Ensure that A and M are coprime
        cout << "Inverse doesn't exist" << endl;
        return -1; // Inverse doesn't exist
    }
    else
    {
        // Ensure x is positive
        return (x % M + M) % M;
    }
}