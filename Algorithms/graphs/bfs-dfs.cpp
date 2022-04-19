#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
// typedef __int128_t bgl;
// range of int valu'es -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main

vi bfs(int r,int V,vector<vi> &A)
{
    vi dist(V, -1);    
    dist[r-1] = 0;
    queue<int> fila;
    fila.push(r);
    while(fila.size()) {
        int u = fila.front(); fila.pop();
        for(int v: A[u-1]) {
            if(dist[v-1] == -1) {
                dist[v-1] = dist[u-1] + 1;
                fila.push(v);
            }
        }
    }
    return dist;
}
void dfs(int r, int &V, vector<vi> &adj, vector<bool> &vis) {
    vis[r] = true;
    for(int v: adj[r]) {
        if(!vis[v]) {
            dfs(v, V, adj, vis);
        }
    }
}

vector<bool> dfsU(int r,int V,vector<vi> &adj) {
    // utility function to dfs
    vector<bool> vis(V, 0);
    dfs(r, V, adj, vis);
    return vis;    
}

void solve()
{
    vector<vi> A = {{2,3,4},{1,5},{1,6,7},{1,8},{2},{3,9},{3},{4},{6}};
    auto dist = bfs(1, 9,A);
    for(int i = 1; i <= 9; i++) {
        cout << i <<": "<<dist[i-1]<<endl; 
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