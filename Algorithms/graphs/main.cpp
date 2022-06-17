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

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<Edge> edges;
        set<pii> connected;
        for(int i = 0; i < V; i++) {
            vvi vc  = adj[i];
            for(auto &vec:vc) {
                int v = vec[0], w = vec[1];
                int x = min(i,v) , y = max(i,v);
                pii e = make_pair(x,y);
                if(connected.find(e)==connected.end()) {
                    edges.pb(Edge(i, v, w));
                    connected.emplace(e);
                }
            }
        }
        int E = edges.size();
        vi ds(V), sz(V);
        dsBuild(V, ds, sz);
        sort(all(edges));
        int total = 0;
        for(int i = 0; i < E; i++) {
            if(dsFind(edges[i].src, ds) != dsFind(edges[i].dest, ds)) {
                dsUnion(edges[i].src, edges[i].dest, ds, sz);
                total += edges[i].w;
            }
        }
        return total;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}