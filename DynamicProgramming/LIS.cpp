#include <bits/stdc++.h>

using namespace std;



/* Problem : Given an array of n integers, find the length of the longest increasing subsequence.
 * n ranges from 1 to 1e5
Example 1:
Input: [10, 9, 2, 5, 3, 7, 101, 18]
Output: 4
Explanation: The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4.

Example 2:
Input: [0, 1, 0, 3, 2, 3]
Output: 4
Explanation: The longest increasing subsequence is [0, 1, 3, 3], therefore the length is 4.

*/

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> dp(n, 1);

    int ans = INT_MIN;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}


int main(){
    solve();
    return 0;
}