// Problem: G. MinOr Tree
// Contest: Codeforces - Codeforces Round #764 (Div. 3)
// URL: https://codeforces.com/contest/1624/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
typedef pair<ll,ll> pll;
typedef vector<pair<ll,ll>> vpll;
const int INF = 0x3f3f3f3f;
const ll INFLL = 8e18;
const int mx = 1e6;
int dp[100001];
char M[100][100];
int R, C;
// N L O S NE SE SO NO
int dr[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};
int V, E;
vi tree_id;

struct Edge {
    ll u, v, w;
    Edge(ll &_u, ll &_v, ll &_w) {
    	u = _u, v = _v, w = _w;
    }
    bool operator<(Edge const &other) {
        return w | other.w;
    }
};

vector<Edge> edges;
void solve()
{
	int t; cin >> t;
	while(t--) {
		cin >> V >> E;
		edges.clear();
		tree_id.assign(V+1, 0);
		for(int i = 1; i<= V; i++)tree_id[i] = i;
		// prim
		for(int i = 1; i <= E; i++) {
			ll u,v, w; cin >> u >> v >> w;
			edges.pb(Edge(u, v, w));
		}
		sort(edges.begin(), edges.end());
		// reverse(all(edges));
		ll mst_cost = 0, ans = -1;
		for(Edge &e : edges) {
			if(tree_id[e.u] != tree_id[e.v]) {
				mst_cost += e.w;
				if(ans == -1) ans = e.w;
				else ans |= e.w;
    			int old_id = tree_id[e.u], new_id = tree_id[e.v];
    			for(int i = 1; i <= V; i++) {
    				if(tree_id[i] == old_id)
    					tree_id[i] = new_id;
    			}
			}
		}
		cout << ans << endl;
	}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
    return 0;
}