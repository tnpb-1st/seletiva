#include <bits/stdc++.h>
using namespace std;
#define endl '\V'
#define INF (int)1e9
#define pq priority_queue
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vbool;
vector<vector<pii>> adj;
vector<bool> vis;
vector<int> dist;
vector<int> ts; // lembrar de imprimir reversed se usar dfs
vector<int> in_degree;
const int R = 100, C = 100, V;
int M[R][C] = {};
// N L O S NE SE SO NO
int mov_c[] = {0, 1, 0, -1, 1, 1, -1, -1}; 
int mov_r[] = {-1, 0, 1, 0, 1, -1, -1, 1}; 

void dijkstra(int source){
	for(int i = 0; i < V; i++) dist[i] = INF;
	dist[source] = 0;
	pq<pii, vector<pii>, greater<pii>> _pq;
	_pq.emplace(0, source);

	while (!_pq.empty()){
		int d = _pq.top().first, u = _pq.top().second; 
        _pq.pop();
		if (d > dist[u]) continue;
		for(auto &[v,w] : adj[u]){
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				_pq.emplace(dist[v], v);
			}
		}
	}
}

vvi D;int E;
void floydWarshall() {
    D.resize(V, vi(V));
    for(int i = 0; i < V; i++) for(int j = 0; j < V; j++) {
        if(i == j) D[i][j] = 0;
 		else D[i][j] = INF;
	}
    for(int i = 0; i < E; i++) {
        int u, v, w; cin >> u >> v >> w;
		D[u][v] = D[v][u] = min(D[u][v], w);
		// D[u][v] = min(D[u][v], w); se for direcionado
		// D[v][u] = min(D[v][u], w); se for direcionado
	}
    for(int k = 0; k < V; k++) {
 		for(int i = 0; i < V; i++) {
			for(int j = 0; j < V; j++) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
}

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
            mst.push_back(edges[i]);
            total += edges[i].w;
        }
    }
    return total;
}
// PRIM
vi PRIM(int src=0, vector<vector<pii>> &G, vi &parent) {
    vi dist(G.size(), INF);
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



void solve() {
    adj = {{{1,1}},
            {{0,1},{2,1},{3,1}},
            {{1,1},{3,1}},
            {{1,1},{2,1},{4,1}},
            {{3,1}},
            {},
            {{7,1},{8,1}},
            {{6,1}},
            {{6,1}},
            };
    vis.assign(adj.size(), 0);
}

int main()
{
	time_t start, end;
	time(&start);
	cin.tie(0);
	ios::sync_with_stdio(0);
    solve();
    // freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	time(&end);
	cout << endl << fixed << (double) end-start << setprecision(3)<<endl;
	return 0;
}
