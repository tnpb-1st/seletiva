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
/*
SOLUTION BY tnpb
*/
struct pll {
    ll val;
    ll w;
    pll(ll value=0, ll wght=0) {
        val = value; w = wght;
    }
};

ll dp[200001], ans[200001];
vector<pll> tree[200001];

ll dfs(ll node, ll par) {
    for(auto u : tree[node]) {
        if(u.val == par) continue;
        dp[node] = max(dp[node], u.w + dfs(u.val, node));
    }
    return dp[node];
}

void dfs1(ll node, ll par, ll parAns = 0) {
    ll max1 = 0, max2=0;
    for(auto u:tree[node]) {
        if(u.val == par) continue;
        ll cur = u.w + dp[u.val];
        if(max1 < cur) swap(max1, cur);
        if(max2 < cur) swap(max2, cur);
    }
    ans[node] = max(parAns, max1);
    for(auto u: tree[node]) {
        if(u.val == par) continue;
        ll cur = u.w + dp[u.val];
        ll maxAnsUp = max(parAns, (max1 != cur) ? max1 : max2);
        dfs1(u.val, node, u.w + maxAnsUp);
    }
}

void solve()
{
    int t; cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)tree[i].clear(), dp[i] = 0, ans[i] = 0;
        ll u, v , w;
        for(int i = 1; i < n; i++) {
            cin >> u >> v >> w;
            tree[u].pb(pll(v,w));
            tree[v].pb(pll(u,w));
        }
        dfs(1,0);
        dfs1(1, 0);
        for(int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
        }
        cout<<endl;
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
