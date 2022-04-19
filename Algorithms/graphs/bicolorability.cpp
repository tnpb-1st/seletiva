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

bool dfs(ll v, vvi &g, vbool &colors, vbool &visited) {
    visited[v] = true;
    for(auto &u:g[v]) {
        if(!visited[u]) {
            colors[u] = !colors[v];
            if(!dfs(u, g, colors, visited)) return false;
        } else if(colors[v] == colors[u]) return false;
    }
    return true;
}

void solve()
{
    vvi g;
    vbool colors(g.size(), false), visited(g.size(), false); 
    bool ans = true;
    for (int i = 0; i < g.size(); i++)
    {
        if(!visited[i]) {
            colors[i] = true;
            ans = ans && dfs(i, g, colors, visited);
        }
    }
    if(ans) {
        cout <<"Bipartide";
    }
    else {
        cout<<"Not bipartide";
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
