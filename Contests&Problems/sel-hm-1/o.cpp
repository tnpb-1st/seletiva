#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
using namespace std;
typedef long long ll;
// typedef __int128_t bgl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main

vector<int> solve(vector<int> arr, vector<int> queries) {
    vector<int> ret(queries.size(),INT32_MAX);
    for(int i = 0; i < queries.size(); i++)
    {
        int maxNum = INT32_MIN;
        deque<int> dq;
        
        for(int j = 0; j < queries[i]; j++)
        {
            if(arr[j] >= maxNum)
            {
                maxNum = arr[j];
            }
            while(dq.size() && (arr[dq.back()] < arr[j]))
            { 
                dq.pop_back();
            }
            
            dq.push_back(j);
        }
        ret[i] = maxNum;
        for(int k = 1; k <= arr.size()-queries[i]; k++)
        {
            if(dq.front() < k) 
            {
                dq.pop_front();
                if(dq.size()) maxNum = arr[dq.front()];
                else maxNum = INT32_MIN;
            }
            if(arr[k + queries[i] - 1] > maxNum)
            {
                maxNum = arr[k + queries[i] - 1];
            }
            while(dq.size() && arr[dq.back()] < arr[k + queries[i] - 1])
            { 
                dq.pop_back();
            }
            dq.push_back(k + queries[i] - 1);
            ret[i] = min(maxNum, ret[i]);
        }
    }
    
    return ret;
 }

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    int n, q;
    vi arr, queries;
    cin>>n>>q;
    int x;
    for(int i=0; i < n; i++)
    {
        cin >> x;
        arr.pb(x);
    }
    for(int j = 0; j < n; j++)
    {
        cin >> x;
        queries.pb(x);
    }

	vi ans = solve(arr, queries);
    for(auto &x:ans)cout<<x<<endl;
	return 0;
}