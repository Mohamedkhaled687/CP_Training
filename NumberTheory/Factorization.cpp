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