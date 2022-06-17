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
// typedef __int128_t bgl;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main
const int inf = 1e9;
const ll infl = 1e18;
ll M[301][301];
int V;



ll djikstra(vector<set<pair<ll,ll>>>&adj, int source, int dest) {
    vll dist(V+1, infl);
    dist[source] = 0;
    pq<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> _pq;
    _pq.emplace(0, source);
    while(!_pq.empty()) {
        int d = _pq.top().first, u = _pq.top().second;
        _pq.pop();

        for(auto &e : adj[u]) {
            int w = e.first, v = e.second;
            if(dist[v] > (ll)dist[u] + w) {
                dist[v] = (ll)dist[u] + w;
                if(v == dest) break;
                _pq.emplace(dist[v], v);
            }
        }        
    }
    return dist[dest];
}

void solve()
{
    int E,Q;
    cin >> V >> E >> Q;
    vector<set<pair<ll,ll>>> adj(V+1);
    for(int i = 0; i < E; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].insert({w,v});
        adj[v].insert({w,u});
        M[u][v]=w;
        M[v][u]=w; 
    }
    while(Q--) {
        int k, u, v;
        cin >> k >> u >> v;
        if(k == 0) {
            adj[u].erase({M[u][v],v});
            adj[v].erase({M[u][v],u});
            M[u][v] = M[v][u] = -1;
        } else {
                ll ans;
                ans = djikstra(adj, u, v);
                if(ans == infl)cout<<"IMPOSSIBLE"<<endl;
                else cout << ans << endl;
            
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
