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
const int INF = 0x3f3f3f3f;
const ll INFLL = 8e18;
const int mx = 1e6;
int dp[100001];
vvpii parent;
int dist[1001][1001], ans[1001][1001];
char M[1001][1001];
int R, C;
// N L O S NE SE SO NO
int dr[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};

class dsu2D{
  vector<vector<int>> sz;
  vector<vector<pii>> parent;

  public:
  dsu2D(int m, int n){
    parent.assign(m+1, vector<pii>(n+1));
    sz.assign(m+1, vector<int>(n+1));
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            parent[i][j] = {i,j};
            sz[i][j] = 1;
        }
    }

  }

  pii find(int r, int c){
    pii mpii = {r,c};
    if(parent[r][c] != mpii) return find(parent[r][c].first,parent[r][c].second);
    return parent[r][c];
  }

  void unite(int r1, int c1, int r2, int c2){
    pii a, b;
    a = find(r1,c1);
    b = find(r2,c2);

    int pr1, pc1, pr2, pc2; // parents of cell 1 and cell 2
    pr1 = a.first, pc1 = a.second, pr2 = b.first, pc2 = b.second;
    if(sz[pr1][pc1] < sz[pr2][pc2]){
        swap(a,b);
        swap(pr1,pr2);
        swap(pc1,pc2);
    } 
    if(a != b) sz[pr1][pc1] += sz[pr2][pc2];
    parent[pr2][pc2] = a;
  }

};

void bfs(int r, int c, dsu2D &ufd) {
    queue<pii> q;dist[r][c] = 0;q.push({r,c});
    int _ans = 0;
    // parent[r][c] = {r,c};
    while(q.size()) {
        pii ii = q.front(); q.pop();
        int _r = ii.first, _c = ii.second;
        for(int i = 0 ; i < 4; i++) {
            int adjr = ii.first + dr[i], adjc = ii.second + dc[i];
            if(adjr <= 0 || adjr > R) continue;
            if(adjc <= 0 || adjc > C) continue;
            if(M[adjr][adjc] == '*') {
                _ans++;
            }
            else if(dist[adjr][adjc] == -1) {
                dist[adjr][adjc] = dist[ii.first][ii.second] + 1;
                ufd.unite(r, c, adjr, adjc);
                // parent[adjr][adjc] = {r,c};
                q.push({adjr,adjc});
            } 
        }
    }
    pii _p = ufd.find(r,c);
    ans[_p.first][_p.second] = _ans;
}

void solve()
{
    int L;
    cin >> R >> C >> L;
    memset(dist, -1, sizeof(dist));
    parent.assign(R, vpii(C, {-1,-1}));
    dsu2D djs(R,C);

    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> M[i][j];
        }
    }
    for(int i = 0; i < L; i++) {
        int r, c; cin >> r >> c;
        int _ans = 0;
        if(dist[r][c] == -1)
            bfs(r, c, djs);
        pii _parent = djs.find(r,c);
        _ans = ans[_parent.first][_parent.second];
        cout << _ans << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
