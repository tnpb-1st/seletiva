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

void Fill(vvi &matrix,vvi &adj, set<pii> &checked,int r0, int c0,int r1, int c1, int &m, int &n) {
    if(r1 < 0 || c1 < 0 || r1 >= m || c1 >=n) return;
    if(matrix[r1][c1] != matrix[r0][c0]) return;
    int v1 = r0 * n + c0;
    int v2 = r1 * n + c1;
    pii p1 = make_pair(v1,v2), p2 = make_pair(v2,v1);
    if(checked.find(p1) == checked.end()) {
        checked.insert(p1);
        checked.insert(p2);
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }
}

void floodFill(vvi& matrix, vvi &adj,set<pii> &checked ,int r, int c, int &m, int &n) {
    if(r < 0 || c < 0 || r >= m || c >=n) return;
    if(matrix[r][c] == (int)'.') return;
    Fill(matrix, adj, checked, r, c, r-1, c, m, n); // norte
    Fill(matrix, adj, checked, r, c, r, c + 1, m, n); // leste
    Fill(matrix, adj, checked, r, c, r+1, c, m, n); // sul
    Fill(matrix, adj, checked, r, c, r, c-1, m, n); // oeste
}

void dfs(int r, vector<vi> &adj, vector<bool> &vis) {
    vis[r] = true;
    for(int v: adj[r]) {
        if(!vis[v]) {
            dfs(v, adj, vis);
        }
    }
}

void solve()
{
    // achar o num de componentes conexas
    int m,n;
    cin>>m>>n;
    vvi adj(m*n);
    vbool vis(m*n, false);
    vvi mtx(m, vi(n));
    set<pii> edges;
    int cc = 0;
    for(int r = 0; r < m; r++) {
        for(int c = 0; c < n; c++) {
            char x;
            cin >> x;
            mtx[r][c] = (int)x;  
        }
    }
    for(int r = 0; r < m; r++) {
        for(int c = 0; c < n; c++) {
            floodFill(mtx, adj, edges, r, c, m, n);
            if(mtx[r][c] == (int)'.')vis[r*n+c] = true;   
        }
    }
    for(int i = 0; i < m*n; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis);
            cc++;
        }
    }
    cout<<cc;
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
