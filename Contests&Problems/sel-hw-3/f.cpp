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
const int INF = 2e9;
const ll INFLL = 8e18;
const int arrLim = 1e6;
int dp[100001];
int idx = 0;
vector<pii> adj[100];
vector<pii> verts;
map<pii, int> keys;
bool visited[101];
int R, C, V, E;
// N L O S NE SE SO NO
int dr[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};

void dfs(int r, int c) {
    visited[keys[{r,c}]] = 1;
    for(auto &[adjr,adjc] : adj[keys[{r,c}]]) {
        if(!visited[keys[{adjr,adjc}]])
            dfs(adjr,adjc);
    }
}

void solve()
{
    memset(visited, 0, sizeof(visited));
    cin >> V;
    for(int i = 0; i < V; i++) {
        int u, v;
        cin >> u >> v;
        verts.pb({u,v});
        keys[{u,v}] = idx++;
    }
    for(auto &[r1,c1] : verts) {
        for(auto &[r2,c2] : verts) {
            if(r2 == r1 && c2 == c1) continue;
            if(r1 == r2 || c1 == c2) { 
                adj[keys[{r1,c1}]].pb({r2,c2});
                adj[keys[{r2,c2}]].pb({r1,c1});
            }
        }
    }
    int CC = 0;
    for(auto &[r,c] : verts) {
        if(!visited[keys[{r,c}]]) {
            dfs(r,c);
            CC++;
        }
    }
    cout << CC - 1;
}

int main()
{
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
