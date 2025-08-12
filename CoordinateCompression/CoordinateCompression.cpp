#include <bits/stdc++.h>
using namespace std;

struct coordinate_compression
{
private:
    vector<int> init;

    void compress(vector<int> &v)
    {
        sort(v.begin(), v.end());                     // sort the vector
        v.erase(unique(v.begin(), v.end()), v.end()); // remove duplicates
    }

public:
    coordinate_compression(vector<int> &arr)
    {
        init = arr;     // store the original vector
        compress(init); // compress the vector
    }

    int index(int val)
    {
        return lower_bound(init.begin(), init.end(), val) - init.begin();
    }

    int initialVal(int idx)
    {
        return init[idx];
    }
};

signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    // Getting the original array
    vector<int> arr(n);

    for (auto &x : arr)
    {
        cin >> x;
    }

    vector<int> v(arr.begin(), arr.end());
    sort(v.begin(), v.end());                     // sort the vector
    v.erase(unique(v.begin(), v.end()), v.end()); // remove duplicates

    // Start coordinate compression
    // Now we will replace each element in arr with its index in the sorted unique vector v
    for (int i = 0; i < n; i++)
    {
        arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
    }

    // output the compressed array
    for (auto &x : arr)
    {
        cout << x << " ";
    }

    cout << endl;

    // output the original array

    for (auto &i : arr)
    {
        cout << v[i] << " ";
    }

    return 0;
}