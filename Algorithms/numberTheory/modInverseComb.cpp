/*
author: eiji_tnpb
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define REP(idx,x) for(int i = idx; i<x; i++)
#define REPN(idx,x) for(int i = idx; i<=x; i++)
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
const int INF = 0x3f3f3f3f;
const ll INFLL = 8e18;
const int mx = 1e6;
int dp[100001];
char M[100][100];
int R, C;
// N L O S NE SE SO NO
int dr[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};
ll fact[501];

ll fastExpo(ll a, ll b, ll MOD){
	a  = (a % MOD + MOD) % MOD;
	ll res = 1;
	while(b) {
		if(b&1)
			res = res * a % MOD;
		a = a *	a % MOD;
		b >>=1;
	}
	return res;
}

ll invMod(ll a, ll MOD) {
	return fastExpo(a, MOD-2, MOD);
}

ll nCk(ll n, ll r, ll MOD, bool rep=false) {
	if(rep) n = n + r - 1;
	return ((fact[n] * invMod(fact[r], MOD) % MOD) * invMod(fact[n-r], MOD)) % MOD;
}

void solve()
{
	
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
    return 0;
}

