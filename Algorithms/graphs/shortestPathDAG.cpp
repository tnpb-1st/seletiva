#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
#define inf 0xfffffff
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef pair<int,int> pii;

vi bfsTopSrt(vector<vector<pii>> &adj,vi &dependencia) {
    pq<int, vi, greater<int>> elem;
    vi ans;
    for(int i = 0; i < adj.size(); i++) {
        if(dependencia[i] == 0) {
            elem.push(i);
        }
    }
    while(!elem.empty()) {
        int v = elem.top();
        elem.pop();
        ans.pb(v);
        for(auto &u:adj[v]) {
            if(--dependencia[u.first] == 0) {
                elem.push(u.first);
            }
        }
	}
    return ans;
}

vi DAGSSP(int src, vector<vector<pii>> &adj, vi &toposorted) {
    // find shortest paths vector in acyclic graph in O(V+E)
    // using both toposort and a kind of a djikstra*
    vi dist(adj.size(), inf);
    dist[src] = 0;
    for(int &u:toposorted) {
        for(pii &pair: adj[u]) {
            if(dist[pair.first] > dist[u] + pair.second) {
                dist[pair.first] = dist[u] + pair.second;
            }
        }
    }
    return dist;
}

void solve()
{
    vector<vector<pii>> Graph(4);
    vi dependencia = {0, 1, 1, 2};
    Graph[0].pb(make_pair(1,1));
    Graph[1].pb(make_pair(2,3));
    Graph[1].pb(make_pair(3,2));
    Graph[2].pb(make_pair(3,4));
    vi toposorted = bfsTopSrt(Graph, dependencia);
    vi dist = DAGSSP(1, Graph, toposorted);
    for(int i = 0; i < 4; i++) {
        cout << i << ' '<< dist[i]<<endl;
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

