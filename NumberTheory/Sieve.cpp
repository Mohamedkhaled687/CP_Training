#include <bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes to find all prime numbers up to n
// complexity: O(n log log n)

const int N = 1e5 + 5;
vector<bool> isPrime(N, true);

void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}
