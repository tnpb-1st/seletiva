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

struct ii {
    int v = -1;
    int w = -1;

    ii(int val, int weight=-1) {v = val,weight=w;}
    void changeWeight(int &new_w) {w = new_w;}
};
// Global
const int num_v = 9;
vector<ii> adj[num_v];
int ans[num_v];

int dfs(int v, int p = -1) {
    for(auto u:adj[v]) {
        if(u.v == p) continue;
        dp[v] = max(dp[v], u.w + dfs(u.v, v));
    }
    return dp[v];
}

void dfs1(int v, int p, int parAns=0) {
    int max1 = 0, max2 = 0;
    for(auto u:adj[v]) {
        if(u.v == p) continue;
        int cur = u.w + dp[u.v];
        if(max1 <  cur) swap(max1,cur);
        if(max2 <  cur) swap(max2,cur);
    }
    ans[v] = max(parAns,max1);
    for(auto u: adj[v]) {
        if(u.v == p) continue;
        int cur = u.w + dp[u.v];
        int maxAnsUp = max(parAns, (max1!=cur) ? max1 : max2);
        dfs1(u.v, v, u.w + maxAnsUp);
    }
}

void solve()
{
   
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
