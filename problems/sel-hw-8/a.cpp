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

int c[100001];
ll dp[100001][2];
ll res[100001] = {};
vll tree[100001];

/*
SOLUTION BY tnpb
*/

void dfs(int node, int parent) {
    ll sum1 = 0, sum2 = 0;

    for(ll &child:tree[node]) {
        if(child != parent)
            dfs(child, node);
        sum1 += dp[child][0];
        sum2 += max(dp[child][0],dp[child][1]);
    }

    dp[node][1] = sum1 + c[node];
    dp[node][0] = sum2;
    res[node] = max(dp[node][1], dp[node][0]);
}

void solve()
{
    int n,a,b; cin>>n;
    for(int i = 1; i< n; i++) {
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    for(int i = 1; i <= n; i++) cin >> c[i];
    dfs(1, - 1);
    cout << res[1];
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
