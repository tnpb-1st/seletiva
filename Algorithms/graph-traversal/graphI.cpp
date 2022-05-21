#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF (int)1e9
#define pq priority_queue
typedef pair<int,int> pii;
vector<vector<pii>> adj;
vector<bool> vis;
vector<int> dist;
vector<int> ts; // lembrar de imprimir reversed se usar dfs
vector<int> in_degree;
const int R = 100, C = 100;
int M[R][C] = {};
// N L O S NE SE SO NO
int mov_c[] = {0, 1, 0, -1, 1, 1, -1, -1}; 
int mov_r[] = {-1, 0, 1, 0, 1, -1, -1, 1}; 

void dfs(int u) {
    vis[u] = true;
    for(auto &[v,w] : adj[u]) {
        if(!vis[v])
            dfs(v);
    }
}

void bfs(int s) {
    dist.assign(adj.size(), INF); dist[s] = 0;
    queue<int> q; q.push(s);
    while(q.size()) {
        int u = q.front(); q.pop();
        for(auto &[v,w] : adj[u]) {
            if(dist[v] != INF) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}

int conectedComponents() {
    int cc = 0;
    vis.assign(adj.size(), false);
    for(int u = 0; u < adj.size(); u++) {
        if(!vis[u]) {
            cc++;
            cout << "CC " << cc << ": ";
            dfs(u);
            cout<<endl;
        }
    }
    return cc;
}

int floodFill(int r, int c, char c1, char c2) {
    // dfs version
    if((r < 0) || (r >= R)) return 0;
    if((c < 0) || (c >= C)) return 0;
    if(M[r][c] != c1 ) return 0;
    int ans = 1;
    M[r][c] = c2; // marcar o vertice para não ficar em loop
    for(int i = 0; i < 8; i++) // i < 4 se apenas N,L,O,S
        ans += floodFill(r + mov_r[i], c + mov_c[i], c1, c2); // faz algo nessa parte
    return ans;
}

void floodFill2(int r, int c) {
    // bfs version
    vector<vector<int>> dis(R,vector<int>(C, INF));dis[r][c] = 0;
    queue<pii> q;q.push({r,c});
    while(q.size()) {
        int _r = q.front().first, _c = q.front().second;q.pop();
        for(int i = 0; i < 4; i++) {
            int adj_r = _r + mov_r[i], adj_c = _c + mov_c[i];
            if(adj_r < 0 || adj_r >= R) continue;
            if(adj_c < 0 || adj_c >= C) continue;
            if(dis[adj_r][adj_c] == INF) {
                dis[adj_r][adj_c] = dis[_r][_c] + 1;
                q.push({adj_r, adj_c});
            }
        }
    }
}

void toposort(int u) {
    // dfs version
    vis[u] = true;
    for(auto &[v,w] : adj[u]) {
        if(!vis[v]) {
            toposort(v);
        }
    }
    ts.push_back(u); // lembrar de imprimir reversed
}

void toposort2(int u) {
    // khan version with bfs
    pq <int, vector<int>, greater<int>> _pq; // min priority queue
    for(int u = 0; u < adj.size(); u++) {
        if(in_degree[u] == 0)
            _pq.push(u);
    }
    while(_pq.size()) {
        int u = _pq.top();_pq.pop();
        ts.push_back(u); // não precisa imprimir reversed
        for(auto &[v, w] : adj[u]) {
            --in_degree[v]; // checar se v.first é o node ou o peso
        if(in_degree[v] > 0) continue;
        _pq.push(v); 
        }
    }
}

bool isBipartite(int s) {
    queue<int> q; q.push(s);
    vector<int> color(adj.size(), INF); color[s] = 0;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(auto &[v, w] : adj[u]) {
            if(color[v] == INF) {
                color[v] = color[u] - 1;
                q.push(v);
            }
            else if(color[v] == color[u]) {
                return false;
            }
        }
    }
    return true;
}

vector<bool> color;
bool isBipartite2(int s) {
    // dfs version
    for(auto &[v,w]: adj[s]) {
        if(!vis[v]) {
            vis[v] = true;
            color[v] = !color[s];
            if(!isBipartite2(v)) return false;
        } else if(color[v] == color[s]) return false;
    }
    return true;
}

void solve() {
    adj = {{{1,1}},
            {{0,1},{2,1},{3,1}},
            {{1,1},{3,1}},
            {{1,1},{2,1},{4,1}},
            {{3,1}},
            {},
            {{7,1},{8,1}},
            {{6,1}},
            {{6,1}},
            };
    vis.assign(adj.size(), 0);
    // dfs(0);
    // bfs(0);
    // for(int i = 0; i < adj.size(); i++){
    //     cout <<"dist from 0 to " << i << ": " << dist[i];
    //     if(i != adj.size()-1) cout << endl;
    // }
    conectedComponents();
}

int main()
{
	time_t start, end;
	time(&start);
	cin.tie(0);
	ios::sync_with_stdio(0);
    solve();
    // freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	time(&end);
	cout << endl << fixed << (double) end-start << setprecision(3)<<endl;
	return 0;
}
