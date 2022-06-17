#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
// typedef __int128_t bgl;
// range of int valu'es -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main
void dfs(int r ,vector<vi> &adj, vi &vis, int &VV, int &V) {
    vis[r] = true;
    V++;
    if(adj[r].size() == 2)VV++;
    for(int v: adj[r]) {
        if(!vis[v]) {
            dfs(v, adj, vis, VV, V);
        }
    }
}

void solve()
{
    int nV, nE, cc=0, ncyc = 0, u, v;
    scanf("%d %d",&nV, &nE);
    vector<vi> adj(nV);
    vi visit(nV, 0), parents(nV, -1);
    for(int i = 0; i < nE; i++) {
        scanf("%d %d",&v, &u);
        adj[v-1].pb(u-1);
        adj[u-1].pb(v-1);
    }
    int V, VV;
    for(int i =0; i < nV; i++) {
        V = VV = 0;
        if(!visit[i]) {
            cc++;
            dfs(i, adj, visit, VV, V);
            if(VV == V)ncyc++;
        }
    }
    printf("%d",ncyc);
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
