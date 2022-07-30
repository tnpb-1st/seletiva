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
ll fact[501];
const ll MOD = 1000000007;

ll nCr(ll n, ll r)
{
	return (fact[n]%MOD/ ((1LL * (fact[n-r]%MOD) * (fact[r]%MOD)) % MOD);
}

ll nCRr(ll n, ll r)
{
	return (fact[n+r-1]%MOD/ ((1LL* (fact[r]%MOD) * (fact[n-1]%MOD)) % MOD);
}

void solve()
{
	fact[0] = 1;
	for(int i = 1; i <= 500; i++) fact[i] = (((1LL * fact[i-1]) % MOD) * i) % MOD;
	int T;
	cin >> T;
	while(T--)
	{
		
	}
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
