#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
#define inf 0x3f3f3f3f
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef pair<int,int> pii;

vi djikstra(vector<vector<pii>> &adj, int source, int w0=0) {
    vi dist(adj.size(), inf);
    vi parent(adj.size(), -1);
    dist[source] = w0;
    parent[source] = source;
    pq<pii, vector<pii>, greater<pii>> _pq;
    _pq.emplace(w0, source);
    while(!_pq.empty()) {
        int d = _pq.top().first, u = _pq.top().second;
        _pq.pop();
        if(dist[u] > d) continue;

        for(auto &e : adj[u]) {
            int w = e.first, v = e.second;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                _pq.emplace(dist[v], v);
            }
        }        
    }
    return dist;
}

vvi floydWarshal(vector<vector<pii>> &adj) {
    int V = adj.size();
    vvi dist(V, vi(V));
    for(int i = 0; i < V; i++) for(int j = 0;j < V; j++) {
        if(i == j) dist[i][j] = 0;
        else dist[i][j] = adj[i][j].first;
    }
    
    for(int v = 0; v < V; v++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                dist[i][j] = min(dist[i][j],dist[i][v] + dist[v][j]); 
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
