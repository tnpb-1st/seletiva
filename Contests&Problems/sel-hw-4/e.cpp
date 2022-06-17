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
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
int V;
int E;
vll cost;
vll parents;
vector<vector<pll>> adj;

void djikstra(ll source) {
    cost = vll(V+1, inf);
    for(int i = 0; i <= V; i++) {
        parents.pb(i);
    }
    cost[source] = 0;
    pq<pll, vector<pll>, greater<pll>> _pq;
    _pq.emplace(0, source);
    while(!_pq.empty()) {
        ll d = _pq.top().first, u = _pq.top().second;
        _pq.pop();

        for(auto &e : adj[u]) {
            ll w = e.first, v = e.second;
            if(cost[v] > (ll)(cost[u] + w)) {
                cost[v] = cost[u] + w;
                parents[v] = u;
                _pq.emplace(cost[v], v);
            }
        }        
    }
}

void solve()
{
    ll u, v, w;
    cin >> V >> E;
    adj = vector<vector<pll>>(V+1);
    stack<ll> ans;
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        adj[u].pb(make_pair(w, v));
        adj[v].pb(make_pair(w, u));
    }
    djikstra(1);
    if(parents[V] == V) cout << -1;
    else {
        ans.push(V);
        int dest = V;
        while(dest != 1) {
            ans.push(parents[dest]);
            dest = parents[dest];
        }
        while(ans.size()) {
            cout << ans.top()<< ' ';
            ans.pop();
        }
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
