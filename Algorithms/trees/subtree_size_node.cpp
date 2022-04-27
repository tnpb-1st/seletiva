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
int dp[100001];

// problem for given an graph of a tree, find the subtree size of each node
vi tree[100001];
int sub[100001];

void dfs(int node, int par) {
	sub[node] = 1;

	for(int &child: tree[node]) {
		if(child != par) {
			dfs(child, node);
			sub[node] += sub[child];
		}
	}
}

int main()
{
	int n, a, b;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		tree[a].pb(b), tree[b].pb(a);
	}
	dfs(1, -1);

	for(int i = 1; i <= n; i++) {
		cout << "Node "<<i<<" Sub["<<i<<"] = "<<sub[i]<<endl;
	}

	return 0;
}
