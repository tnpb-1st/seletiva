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
vector<set<int>> adj;
char M[100][100];
int R, C, V;
// N L O S NE SE SO NO
int dr[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};

bool bfs(int s, vi &bfsQ) {
    if(bfsQ[0] != s) return false;
    vi dist(V+1, INF); dist[s] = 0;
    int p = 1;
    queue<int> q;q.push(s);
    while(q.size()) {
        int u = q.front(); q.pop();
        auto e = adj[u].begin();
        set<int> nvs;
        for(int i = 0; i < adj[u].size(); i++, e++) {
            if (dist[*e] == INF)
                nvs.insert(*e);
        }
        for(int i = 0; i < nvs.size(); i++) {
            if(nvs.count(bfsQ[p])) {
                q.push(bfsQ[p]);
                dist[bfsQ[p]] = dist[u] + 1;
                p++;
            } else return false;
        }
    }
    return true;
}

void solve()
{
    cin >> V;
    adj.assign(V+1, set<int>());
    for(int i = 1; i < V; i++) {
        int u,v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<int> bfsCand;
    int x;
    while(cin >> x) 
        bfsCand.push_back(x);
    if(bfs(1, bfsCand))
        cout << "YES";
    else
        cout << "NO";

}

int main()
{
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
