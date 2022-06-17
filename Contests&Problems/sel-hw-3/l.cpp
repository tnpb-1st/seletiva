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
// typedef __int128_t bgl;
// range of int valu'es -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main
pii bfs(int r,int V,vector<vi> &A)
{
    vi dist(V, -1);    
    dist[r] = 0;
    int biggest_dist = 0, far_neighboord = r;
    queue<int> fila;
    fila.push(r);
    while(fila.size()) {
        int u = fila.front(); fila.pop();
        for(int v: A[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                fila.push(v);
                if(dist[v] > biggest_dist){
                    biggest_dist = dist[v];
                    far_neighboord = v;
                }
            }
        }
    }
    return make_pair(biggest_dist, far_neighboord);
}

void solve()
{
    int n;
    cin >> n;
    if(n == 1)cout<<0;
    else {
        vvi G(n);
        int u,v;
        vi freq(n, 0);
        int root;
        int max_freq = -1;
        for(int i = 0; i < n-1; i++) {
            cin >> u >> v;
            u--;v--;
            G[u].pb(v);
            G[v].pb(u);
            freq[u]++;
            freq[v]++;
            if(freq[u] > max_freq) {
                root = u;
                max_freq = freq[u];
            }
            if(freq[v] > max_freq) {
                root = v;
                max_freq = freq[v];
            }
        }
        pii my_p = bfs(root, n, G);
        my_p = bfs(my_p.second, n, G);
        int ans = my_p.first * 3;
        cout<<ans;
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