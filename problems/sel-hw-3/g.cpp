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

bool dfs(ll v, vvll &g, vbool &colors, vbool &visited) {
    visited[v] = true;
    for(auto &u:g[v]) {
        if(!visited[u]) {
            colors[u] = !colors[v];
            if(!dfs(u, g, colors, visited)) return false;
        } else if(colors[v] == colors[u]) return false;
    }
    return true;
}
void solve()
{
    int T;
    scanf(" %d", &T);
    for(int t = 1; t<= T; t++) {
        int V, E;
        scanf(" %d %d", &V, &E);
        vvll g(V);
        vbool colors(V, false), visited(V, false);
        ll u,v;
        for(int e = 0; e < E; e++) {
            scanf(" %lld %lld",&u, &v);
            g[u-1].pb(v-1);
            g[v-1].pb(u-1);
        }

        bool ans = true;
        for(ll u = 0; u < V; u++) {
            if(!visited[u]) {
                colors[u] = true;
                ans = ans && dfs(u, g, colors, visited);
            }
        }
        printf("Scenario #%d:\n", t);
        if(!ans) {
            printf("Suspicious bugs found!\n");
        } else {
            printf("No suspicious bugs found!\n");
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
