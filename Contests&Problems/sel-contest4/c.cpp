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
vvi adj;
vi color;
int dp[100001];
char M[100][100];
int R, C, V, E;
// N L O S NE SE SO NO
int dr[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};

bool isBipartite(int s) {
    queue<int> q; q.push(s); color[s] = 0;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(auto &v : adj[u]) {
            if(color[v] == INF) {
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if(color[v] == color[u]) {
                return false;
            }
        }
    }
    return true;
}

void solve()
{
    cin >> V >> E;
    adj.assign(V+1, {});color.resize(V+1, INF);
    for(int i = 0; i < E; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bool isPossible = true;
    for(int u = 1; u <= V; u++) {
        if(color[u] == INF) {
            if(!isBipartite(u)) {
                isPossible = false;
                break;
            }
        }
    }
    if(!isPossible) cout << -1;
    else {
        vi v1, v2;
        int c1 = color[1];
        for(int i = 1; i <= V; i++) {
            if(color[i] == c1 && adj[i].size()) v1.pb(i);
            if (color[i] != c1) v2.pb(i);
        }
        // print v1
        cout << v1.size()<<endl;
        for(auto &x: v1) cout << x << ' ';
        cout << endl;
        cout << v2.size() << endl;
        for(auto &x: v2) cout << x << ' ';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
