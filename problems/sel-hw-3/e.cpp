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
typedef vector<bool> vbool;
typedef pair<int,int> pii;
// typedef __int128_t bgl;
// range of int valu'es -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main
void dfs(int r, vector<set<int>> &adj, vector<bool> &vis, queue<int> &ans) {
    ans.push(r);
    vis[r] = true;
    for(int v: adj[r]) {
        if(!vis[v]) {
            dfs(v, adj, vis,ans);
        }
    }
}

vi bfs(int r,vector<vi> &A, vbool &vis)
{
    vi ans;
    priority_queue<int, vi ,greater<int>> fila;
    fila.push(r);
    vis[r] = true;
    while(fila.size()) {
        int u = fila.top(); fila.pop();
        for(int v: A[u]) {
            if(!vis[v]) {
                fila.push(v);
                vis[v] = true;
            }
        }
        ans.pb(u);
    }
    return ans;
}

void solve()
{
    int n, e;
    cin >> n >> e;
    vvi adj(n+1);
    vector<bool> visit(n+1, false);
    visit[0] = true;
    int v, u;
    for(int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    vi ans = bfs(1, adj, visit);
    for(auto it = ans.begin(); it != ans.end(); it++) {
        if(it + 1 == ans.end())cout<<*it;
        else cout<<*it<<' ';
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
