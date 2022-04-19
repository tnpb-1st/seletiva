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
// g++ -std=c++11 test.cpp -o main
int bfs(int n, int &m ,vi &dist)
{
    queue<int> fila;
    dist[n] = 0;
    fila.push(n);
    while(fila.size()) {
        int u = fila.front();fila.pop();
        if(u * 2 <= 10000 && dist[u*2] > dist[u] + 1) {
            dist[u*2] = dist[u] + 1;
            if((u * 2) == m) return dist[m];
            fila.push(u*2);
        }
        if(u - 1 >= 0 && dist[u-1] > dist[u] + 1) {
            dist[u-1] = dist[u] + 1;
            if(u-1 == m) return dist[m];
            fila.push(u-1);
        }
    }
    return -1;
}


void solve()
{
    vi dist(10001, INT_MAX);
    int n,  m;
    scanf("%d %d", &n, &m);
    int dist_m = bfs(n, m, dist);
    printf("%d", dist_m);
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
