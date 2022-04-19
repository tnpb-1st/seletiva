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
void dfs(int r,int &m, int &res,int crtcat, vector<vi> &adj, vector<bool> &vis, vector<int> &cats) {
    vis[r] = true;
    if(cats[r])crtcat++;
    else crtcat = 0;
    if(crtcat > m) return;
    if(adj[r].size() == 1 && vis[adj[r][0]]){res++;return;}
    if(adj[r].empty()){res++;return;}
    for(int v: adj[r]) {
        if(!vis[v]) {
            dfs(v, m, res,crtcat, adj, vis, cats);
        }
    }
}

void solve()
{
    int n, m, u, v, rest = 0;
    scanf("%d %d",&n,&m);
    vector<vi> G(n);
    vector<bool> vis(n,false);
    vi cats(n);
    for(int i = 0;i < n ;i++ ) {
        scanf("%d", &u);
        cats[i] = u;
    }
    for(int i =0; i < n-1; i++){
        scanf("%d %d",&u,&v);
        G[u-1].pb(v-1);
        G[v-1].pb(u-1);
    }
    dfs(0, m, rest, 0, G, vis, cats);
    printf("%d", rest);
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
