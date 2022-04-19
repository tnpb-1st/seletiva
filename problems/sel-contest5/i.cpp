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
int dist[51];
vi adj[51];

ll power(ll x, ll &y)
{
	// 3^5 = 3^101
	ll res = 1;
	int n = y;
	while(y > 0) {
        if(y & 1 == 0) {
            x = x * x;
            y = y / 2;
        } else {
            res = res * x;
            y = y - 1;
        }
    }
	return res;
}

void bfs(int &r,int &V, ll &ccE)
{  
    dist[r] = 0;
    queue<int> fila;
    fila.push(r);
    while(fila.size()) {
        int u = fila.front(); fila.pop();
        for(int v: adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                fila.push(v);
                ccE++;
            }
        }
    }
}

void solve()
{
    int V, E, u, v;
    ll compEdges = 0;
    cin >> V >> E;
    for(int i = 1; i <= V; i++) {
        dist[i] = -1;
        adj[i] = vi(0);
    }
    for(int i = 0; i < E; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= V; i++) {
        if(dist[i] == -1) {
            bfs(i, V, compEdges);
        }
    }
    ll ans = 1;
    if(compEdges >= 1) {
        ans = power(2, compEdges);
    }
    cout<<ans;
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