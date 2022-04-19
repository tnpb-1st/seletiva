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

int ans = 0;

int dfs(int r, vector<vi> &adj, vector<bool> &vis, vi &dp) {
    vis[r] = true;
    int longest_path = 0;
    int path;
    for(int v: adj[r]) {
        if(!vis[v]) {
            path = dfs(v, adj, vis, dp);
        }
        else {
            path = dp[v];
        }
        longest_path = max(longest_path, path + 1);
    }
    ans = max(longest_path, ans);
    return dp[r] = longest_path;
}

void solve()
{
    int V, E, u, v;
    cin >> V >> E;
    vvi G(V+1, vi());
    vi dp(V+1, 0);
    vbool visited(V+1, false);
    for(int i =0; i < E; i++) {
        cin >> u >> v;
        G[u].pb(v);
    }

    for(int i = 1; i <= V; i++) {
        if(!visited[i]) {
            dfs(i, G, visited, dp);
        }
    }
    cout << ans;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout)

	solve();
	return 0;
}
