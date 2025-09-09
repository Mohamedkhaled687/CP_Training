#include <bits/stdc++.h>
using namespace std;

vector<int> fact(int n)
{
    vector<int> result;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            result.push_back(i);
            if (i != n / i)
                result.push_back(n / i);
        }
    }
    sort(result.begin(), result.end());
    return result;
}

// Problem given an number 1 <= n <= 1e5

/*
Recently Luba learned about a special kind of numbers that she calls beautiful numbers. The number is called beautiful iff its binary representation consists of k + 1 consecutive ones, and then k consecutive zeroes.

Some examples of beautiful numbers:

12 (110);
1102 (610);
11110002 (12010);
1111100002 (49610).
More formally, the number is beautiful iff there exists some positive integer k such that the number is equal to (2k - 1) * (2k - 1).

Luba has got an integer number n, and she wants to find its greatest beautiful divisor. Help her to find it!

Input
The only line of input contains one number n (1 ≤ n ≤ 105) — the number Luba has got.

Output
Output one number — the greatest beautiful divisor of Luba's number. It is obvious that the answer always exists.
*/

signed main()
{
    int n;
    cin >> n;

    vector<int> divisors = fact(n);
    int mx = INT_MIN;

    auto compute = [&](int k)
    {
        int x = 1 << (k);
        int y = 1 << (k - 1);
        return (x - 1) * y;
    };

    for (auto &i : divisors)
    {
        int ones_count = __builtin_popcount(i);
        int zeros_count = __builtin_ctz(i);
        if ((ones_count == zeros_count + 1) && compute(ones_count) == i)
        {
            mx = max(mx, i);
        }
    }

    cout << mx << endl;
}