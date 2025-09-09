#include <bits/stdc++.h>

using namespace std;

// Problem is given an array you want to find the number of subarrays that equal to given sum;

signed main()
{
    int n, target;
    cin >> n >> target;

    int arr[n + 1] = {};

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1]; // prefix sum
    }

    map<int, int> freq;
    int ans = 0;

    for (int i = 0; i <= n; i++)
    {
        int req = arr[i] - target; // required prefix sum to get the target sum
        ans += freq[req];
        freq[arr[i]]++;
    }
    cout << ans << endl;

    return 0;
}

// Another problem

// Given an array find the max subarray sum
void Max_Subarray_Sum()
{
    int n;
    cin >> n;

    int sum = 0, mn = INT_MAX, ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        sum += x;
        ans = max(ans, sum - mn);
        mn = min(mn, sum);
    }

    cout << ans << endl;
}

// Another Problem

// Given an array find the number of subarrays with sum divible by n

void Subarray_Divisibility()
{
    int n;
    cin >> n;

    map<int, int> freq;
    int sum = 0, ans = 0;
    auto take_mode = [](int x, int mode)
    {
        return (x % mode + mode) % mode;
    };
    freq[0] = 1; // to count subarrays starting from index 1
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sum += x; // sum of elements
        int mod = take_mode(sum, n);
        ans += freq[mod];
        freq[mod]++;
    }
    cout << ans << endl;
}