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
void bfsTopSrt(vvi &adj,vi &dependencia, vi &ans) {
    pq<int, vi, greater<int>> elem;
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
            if(--dependencia[u] == 0) {
                elem.push(u);
            }
        }
    }
}

void solve() {
    int n, e;
    scanf("%d %d", &n, &e);
    vvi G(n);
    vi depen(n, 0), ans;
    int u,v;
    for(int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        G[u-1].pb(v-1);
        depen[v-1]++;
        
    }
    bfsTopSrt(G, depen, ans);
    if(ans.size() != n) {
        printf("Sandro fails.\n");
    } else {
        for(int &v: ans) {
            printf("%d ", v + 1);
        }
        printf("\n");
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
