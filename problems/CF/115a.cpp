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
void bfs(int r,int V, int &max_depth,vector<vi> &A, vector<bool> &visit)
{
    vi dist(V, -1);    
    dist[r] = 1;
    queue<int> fila;
    fila.push(r);
    while(fila.size()) {
        int u = fila.front(); fila.pop();
        visit[u] = true;    
        if(dist[u] > max_depth) max_depth = dist[u];
        for(int v: A[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                fila.push(v);
            }
        }
    }
}

void solve()
{
    int n,u, max_depth=0;
    scanf("%d", &n);
    vector<vi> G(n);
    vector<bool> visit(n, false);
    for(int v = 0; v < n; v++) {
        scanf("%d", &u);
        if(u >= 1){
            G[u-1].pb(v);
        }
    }
    for(int v = 0; v < n; v++) {
        if(!visit[v]) {
            bfs(v, n, max_depth, G, visit);
        }
    }
    printf("%d", max_depth);
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
