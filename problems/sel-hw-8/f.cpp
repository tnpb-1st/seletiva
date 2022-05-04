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
const int inf = 1e9;
const ll infl = 1e18;
const int arrLim = 1e8;
int dp1[50001][501], dp2[50001][501];
// dp1 stores all the nodes with a dist between[0,500] from the src in the subtree of src
// dp2 stores all the nodes with a dist between[0,500] from the src in the tree
vi tree[50001];
/*
SOLUTION BY tnpb
*/

void dfs(int src, int par, int &k) {
	for(int &child: tree[src]) {
		if(child!=par)
			dfs(child,src,k);
	}
	dp1[src][0] = 1; // só o proprio no esta a uma dist 0 dele msm
	for(int dist = 1; dist <= k; dist++) {
		dp1[src][dist] = 0;
		for(int &child: tree[src]) {
			if(child != par)
				dp1[src][dist] += dp1[child][dist-1]; // se esta a uma disancia x do src
				// estara a uma distancia x-1 de um filho
		}
	}
}

void calcDP2(int src, int par, int &k) {
	// funcion that calculates the number of total nodes with a 0 <= dist <= 500
	for(int dist = 0; dist <= k; dist++) {
		dp2[src][dist] = dp1[src][dist];
	}

	if(par != 0) { // apenas para a raiz, todos os nos da arvore estarão em sua subarvore
		dp2[src][1] += dp2[par][0];
		for(int dist=2; dist <= k; dist++) {
			dp2[src][dist] += dp2[par][dist-1];
			dp2[src][dist] -= dp1[src][dist-2];
		}
	}

	for(int &child : tree[src]) {
		if(child != par) {
			calcDP2(child, src, k);
		}
	}
}

void solve() {
	int n,k, u, v;

	cin >> n >> k;
	for(int i = 1; i <= n-1; i++) {
		cin >> u >> v;
		tree[u].pb(v);
		tree[v].pb(u);
	}

	dfs(1,0,k);
	calcDP2(1,0,k);

	ll ans = 0;
	for(int i = 1; i<= n; i++)
		ans += dp2[i][k];
	cout << (ans/2);
	
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	solve();
	return 0;
}
