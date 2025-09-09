#include <bits/stdc++.h>

using namespace std;

vector<int> PrimeFact(int n)
{
    vector<int> result;

    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            result.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        result.push_back(n);
    return result;
}

signed main()
{

    int n;
    cin >> n;

    vector<int> prime_factors = PrimeFact(n);
    for (int p : prime_factors)
    {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}