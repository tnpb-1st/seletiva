#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define pq priority_queue
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<bool> vbool;
typedef pair<int,int> pii;
#define int ll
// typedef __int128_t bgl;
// range of int valu'es -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main
int m,n,T;
vi mov_x = {-1,0,1,0}, mov_y = {0,1,0,-1};
bitset<100001> visited;
int get_pos(int &r, int &c) {
    return r*n+c;
}
void dfs(int r, int c, int &ans, vector<vector<char>> &adj) {
    if(r < 0 || c < 0 || r >= m || c>= n)return;
    if(adj[r][c] == '*') {
        ans++;
        return;
    }
    if(visited[get_pos(r,c)]) return;
    visited[get_pos(r,c)] = true;
    for(int i = 0; i < 4; i++) {
        dfs(r + mov_x[i], c + mov_y[i], ans, adj);
    }
    return;
}
void solve()
{
    cin >> m >> n >> T;
    vector<vector<char>> G(m, vector<char>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin>>G[i][j];
        }
    }
    int ans, x, y;
    for(int t = 0; t < T; t++) {
        cin >> x >> y;
        x--;y--;
        visited.reset();
        ans = 0;
        if(!visited[get_pos(x,y)]) dfs(x,y, ans, G);
        cout << ans << endl;
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
