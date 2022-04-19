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
// Kruskal
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

int kruskal(vector<vector<pii>> &adj, vector<Edge> &edges, vector<Edge> &mst) {
    int E = edges.size();
    int V = adj.size();
    vi ds(V), sz(V);
    dsBuild(V, ds, sz);
    sort(all(edges));
    ll total = 0;
    for(int i = 0; i < E; i++) {
        if(dsFind(edges[i].src, ds) != dsFind(edges[i].dest, ds)) {
            dsUnion(edges[i].src, edges[i].dest, ds, sz);
            mst.pb(edges[i]);
            total += edges[i].w;
        }
    }
    return total;
}
// PRIM
vi PRIM(int src=0, vector<vector<pii>> &G, vi &parent) {
    vi dist(G.size(), inf);
    vbool inMST(G.size(), false);
    inMST[src] = true;
    dist[src] = 0;
    parent[src] = src;
    pq<pii, vector<pii>, greater<pii>> my_pq;
    my_pq.emplace(0, src);
    while(!my_pq.empty()) {
        int d = my_pq.top().first, u = my_pq.top().second;
        my_pq.pop();
        if(inMST[u])continue;
        inMST[u] = true;
        for(auto &my_pair:G[u]) {
            int v = my_pair.second, w = my_pair.first;
            if(!inMST[v] && w < dist[v]) {
                parent[v] = u;
                dist[v] = w;
                my_pq.emplace(make_pair(dist[v], v));
            } 
        }
    }
    return dist;
}


void solve()
{

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
