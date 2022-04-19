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

bitset<100001> visited;
map<pii,int> indexes;
int adj_pos(int &r, int &c, int &n) {return r*n + c;}

void FillAdjMtx(vvi &matrix,vector<vector<pii>> &adj, set<pii> &checked,int r1, int c1,int r2, int c2, int &m, int &n) {
    // fill adjcency matrix
    if(r2 < 0 || c2 < 0 || r2 >= m || c2 >=n || matrix[r2][c2] == 0) return;
    int v1 = indexes[{r1, c1}];
    int v2 = indexes[{r2, c2}];
    pii p1 = make_pair(v1,v2), p2 = make_pair(v2,v1);
    if(checked.find(p1) == checked.end()) {
        checked.insert(p1);
        checked.insert(p2);
        adj[v1].pb(make_pair(r2, c2));
        adj[v2].pb(make_pair(r1,c1));
    }
}

void floodFillAdjMtx(vvi& matrix,vector<vector<pii>> &adj,set<pii> &checked ,int r, int c, int &m, int &n) {
    if(r < 0 || c < 0 || r >= m || c >=n) return;
    vi mov_x = {-1,0,1,0}, mov_y = {0,1,0,-1}; // N,L,S,O
    for(int i = 0; i < 4; i++) {
        FillAdjMtx(matrix, adj, checked, r, c, r+mov_x[i],c+mov_y[i], m, n);
    }
}

void FillPaints(vvi &matrix,int r1, int c1,int r2, int c2, int &m, int &n, int &node_paintings) {
    if(r2 < 0 || c2 < 0 || r2 >= m || c2 >=n || matrix[r2][c2] == 1) return;
    node_paintings++;
}

int floodFillPaints(vvi& matrix,int r, int c, int &m, int &n) {
    if(r < 0 || c < 0 || r >= m || c >=n) return 0;
    int node_paintings = 0;
    vi mov_x = {-1,0,1,0}, mov_y = {0,1,0,-1}; // N,L,S,O
    for(int i = 0; i < 4; i++) {
        FillPaints(matrix, r, c, r+mov_x[i],c+mov_y[i], m, n, node_paintings);
    }
    return node_paintings;
}

void dfs(int &r0, int &c0,int &m, int &n ,vector<vector<pii>> &adj,vvi &mtx ,int &visited_paintings) {
    visited_paintings += floodFillPaints(mtx, r0, c0, m, n);
    pii pairr;
    pairr = make_pair(r0,c0);
    int posr = indexes[pairr];
    visited[posr] = true;
    for(pii &pairv: adj[posr]) {
        if(!visited[indexes[pairv]]) {
            dfs(pairv.first, pairv.second, m, n, adj, mtx, visited_paintings);
        }
    }
}

void solve()
{
    int m, n, T;
    cin >> m >> n >> T;
    
    vector<vector<pii>> G;
    vvi mtx(m, vi(n));
    int g_v = 0;
    set<pii> edges;
    for(int r = 0; r < m; r++) {
        for(int c = 0; c < n; c++) {
            char cell;
            cin >> cell;
            if(cell == '.') {
                mtx[r][c] = 1;
                G.pb({});
                pii pos = make_pair(r,c);
                indexes[pos] = g_v;
                g_v++; 
            }
            else if(cell == '*')mtx[r][c] = 0;
        }
    }
    for(int r = 0; r < m; r++) {
        for(int c = 0; c < n; c++) {
            if(mtx[r][c] == 1) {
                floodFillAdjMtx(mtx, G, edges, r, c, m, n);
            }
        }
    }
    int r0, c0;
    while(T--) {
        cin >> r0 >> c0;
        r0--;c0--;
        int ans = 0;
        visited.reset();
        dfs(r0,c0,m,n, G, mtx, ans);
        cout<<ans<<endl;
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
