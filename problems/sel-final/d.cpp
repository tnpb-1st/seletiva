// C++ implementation of the above approach
#include <bits/stdc++.h>
#define maxLen 30
using namespace std;
typedef long long ll;
 
// Function to find required value
ll findCnt(ll arr[], ll n, ll k)
{
    // Variable to store final answer
    ll ans = 0;
 
    // Loop to find prefix-sum
    for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
        if (arr[i] > k or arr[i] < -1 * k)
            ans++;
    }
 
    if (arr[0] > k || arr[0] < -1 * k)
        ans++;
 
    // Sorting prefix-sum array
    sort(arr, arr + n);
 
    // Loop to find upper_bound
    // for each element
    for (int i = 0; i < n; i++)
        ans += n -
       (upper_bound(arr, arr + n, arr[i] + k) - arr);
 
    // Returning final answer
    return ans;
}

ll findSubarraySum(ll arr[], ll n, ll sum)
{
    unordered_map<ll, ll> prevSum;
 
    ll res = 0;
    ll currSum = 0;
 
    for (int i = 0; i < n; i++) {

        currSum += arr[i];
 
        if (currSum == sum)
            res++;
 
        if (prevSum.find(currSum - sum) != prevSum.end())
            res += (prevSum[currSum - sum]);

        prevSum[currSum]++;
    }
 
    return res;
}
 
// Driver code
int main()
{
    ll m, k; cin >> m >> k;
    ll arr[m];
    for(int i = 0; i < m; i++) cin >> arr[i];
    ll n = sizeof(arr) / sizeof(ll);
 
    // Function to find required value
    ll ans = findSubarraySum(arr, n, k) + findCnt(arr, n, k);
    cout << ans;
}