#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
const int inf = 1e9;
const ll infl = 1e18;
const int arrLim = 1e6;
int dp[100001];
/*
SOLUTION BY tnpb
*/

void solve()
{
    int t;cin>>t;
    const ll mod = 1e9 + 7;
    while(t--) {
        int n;
        cin >> n;
        set<ll> arr[n+1];
        string s;
        ll x;
        cin.ignore();
        for(int i = 1; i<= n; i++) {
            getline(cin,s);
            stringstream S(s);
            while( S >> x)
                arr[i].emplace(x);
        }
        ll ans = 0;
        for(auto ele : arr[1]) {
            ll calc = 1;
            set<ll> used;
            for(int i = 2; i <= n; i++) {
                calc = calc * (arr[i].size() - (arr[i].find(ele) != arr[i].end() ? 1 : 0))%mod;
            }
        } 
    }
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	solve();
	return 0;
}
