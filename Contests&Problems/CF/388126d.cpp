// Problem: D. Time to go back
// Contest: Codeforces - 2 de Julho - div 2
// URL: https://codeforces.com/group/yc7Yxny414/contest/388126/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
const int ms = 1050;
ll fact[ms];
const ll MOD = 1000000007;

void init()
{
	fact[0] = fact[1] = 1;
	for(int i = 2; i <= 1049; i++) fact[i] = (1LL * fact[i-1] * i) % MOD;
}

ll fastExpo(ll a, ll b){
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

ll invMod(ll a) {
	return fastExpo(a, MOD-2);
}

ll nCr(ll n, ll r) {
	if((n >= r) && (n >= 0) && (r >= 0)){
	    ll t1 = (fact[n]), t2 = invMod(fact[r]) % MOD, t3 = invMod(fact[n-r])%MOD;
	    return (((t1 * t2) % MOD) * t3) % MOD;
	}
	return 0;
}

void solve()
{
	int T; cin >> T;
	while(T--)
	{
		ll N,M,K,D; cin >> N >> M >> K >> D;
		vll A(N);for(int i = 0; i < N; i++) cin >> A[i];
		int i0 = -1; // indice onde ocorre o primeiro valor >= D
		sort(all(A));
		auto itr = lower_bound(A.begin(),A.end(),D);
		if(itr != A.end()) i0 = itr - A.begin();
		int expG = N-i0; // qtde de elementos com valor >= D
		
		ll ans = 0;
		// e -> qtde presentes caros
		for(ll k = K; (k <= expG) && (i0 != -1); k++) // eCk * (m-k)C(N-e-k), enquanto k <= e 
		{
			ll part = 0;
			part += nCr(expG, k);
			part = (1LL * (part * (nCr(N-expG,M-k) % MOD)) % MOD);
			ans = ((ans%MOD) + (part%MOD))%MOD;
		}
		cout << ans << endl;
	}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    init();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
