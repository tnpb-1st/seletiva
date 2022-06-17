#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
#define inf 0xfffffff
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
// Kruskal
int degree[200001] = {};

void dsBuild(int n, vi &ds, vi &sz) {
    for(int i = 1; i <= n; i++) {
        ds[i] = i;
        sz[i] = 1;
    }
}

int dsFind(int i, vi &ds) {
    if(ds[i] != i) ds[i] = dsFind(ds[i], ds);
    return ds[i];
}

void dsUnion(int a, int b, vi &ds, vi &sz) {
    a = dsFind(a, ds); b = dsFind(b, ds);
    if(sz[a] < sz[b]) swap(a,b);
    if(a != b) sz[a] += sz[b];
    ds[b] = a;
}

void solve()
{
    int u, v, V, E;
    
    cin >> V >> E;
    vi ds(V+1), sz(V+1);
    dsBuild(V, ds, sz);
    vvi G(V+1);
    vpii mst, edges;
    int mx = 0, bigV;
    for(int i = 0; i < E; i++) {
        cin >> u >> v;
        edges.pb(make_pair(u,v));
        G[v].pb(u);
        G[u].pb(v);
        degree[u]++;
        degree[v]++;
        if(degree[v] > mx) {
            mx = degree[v];
            bigV = v;
        }
        if(degree[u] > mx) {
            mx = degree[u];
            bigV = u;
        }
    }
    for(auto &v: G[bigV]) {
        mst.pb(make_pair(bigV, v));
        dsUnion(bigV, v, ds, sz);
    }

    for(auto &pair:edges) {
        if(dsFind(pair.second, ds) == dsFind(pair.first, ds)) continue;
        mst.pb(make_pair(pair.second, pair.first));
        dsUnion(pair.second, pair.first, ds, sz);
    }


    for(auto &e:mst) {
        cout << e.first << ' ' << e.second << endl;
    }

}

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	solve();
	return 0;
}
