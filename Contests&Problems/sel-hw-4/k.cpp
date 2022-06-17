#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
#define inf 1e18
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
// typedef __int128_t bgl;
// range of int valu'es -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main
vi ds, sz;
struct Edge {
    int src, dest, w;
    Edge(int s, int d, int wt=0) {
        src = s, dest = d, w = wt;
    }
    bool operator < (Edge b) {
        return this->w < b.w;
    }
};

void dsBuild(int n, vi &ds, vi &sz) {
    for(int i = 0; i < n; i++) {
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

int kruskal(int V, vector<Edge> &edges) {
    int E = edges.size();
    ds = sz = vi(V);
    dsBuild(V, ds, sz);
    sort(all(edges));
    int biggest = 0;
    ll total = 0;
    for(int i = 0; i < E; i++) {
        if(dsFind(edges[i].src, ds) != dsFind(edges[i].dest, ds)) {
            dsUnion(edges[i].src, edges[i].dest, ds, sz);
            biggest = max(biggest, edges[i].w);
            total += edges[i].w;
        }
    }
    return biggest;
}
void solve()
{
    int V, E;
    while(cin >> V >> E && (V != 0 || E != 0)) {
        vector<Edge> edges;
        int u,v,w;
        for (int i = 0; i < E; i++)
        {
            cin >> u >> v >> w;
            edges.pb(Edge(u, v, w));
        }
        int max_dist = kruskal(V, edges);
        int mx = 0;
        for(int i = 0; i < V; i++) mx = max(sz[i],mx);
        if(mx != V) {
            cout << "IMPOSSIBLE"<<endl;
        } else {
            cout << max_dist << endl;
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
