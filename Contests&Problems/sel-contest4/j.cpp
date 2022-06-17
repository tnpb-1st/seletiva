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
char M[100][100];
int R, C;
vvi adj;
int V;
// N L O S NE SE SO NO
int dr[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};

vi bfsM(vi &F) {
    vi dist(V+1, INF);
    queue<int> q;
    for(auto &u: F) {
        q.push(u);
        dist[u] = 0;
    }
    while(q.size()) {
        int u = q.front();q.pop();
        for(auto &v: adj[u]) {
            if(dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

vi bfs(int s) {
    vi dist(V+1, INF); dist[s] = 0;  
    queue<int> q; q.push(s);
    while(q.size()) {
        int u = q.front();q.pop();
        for(auto &v : adj[u]) {
            if(dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

void solve()
{
    int t; cin >> t;
    while(t--) {
        int nF;
        cin >> V >> nF;
        adj.assign(V+1, {});
        vi frds;
        for(int i = 0; i < nF; i++) {
            int x; cin >> x;
            frds.pb(x);
        }
        for(int i = 1; i < V; i++) {
            int u, v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vi distF = bfsM(frds);
        vi distV = bfs(1);
        
        vi rooms; bool isPossible = false;
        for(int i = 2; i <= V; i++)
            if(adj[i].size() == 1)
                rooms.pb(i);
        
        for(auto &r:rooms) {
            if(distV[r] < distF[r]) {
                isPossible = true;
                break;
            }
        }
        if(isPossible) {
            cout << "YES"<<endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
