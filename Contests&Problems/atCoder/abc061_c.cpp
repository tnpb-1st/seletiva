// Problem: C - Big Array
// Contest: AtCoder - AtCoder Beginner Contest 061
// URL: https://atcoder.jp/contests/abc061/tasks/abc061_c
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
author: eiji_tnpb
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define forn(idx,i,x) for(int i = idx; i<=x; i++)
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
const int MX = 1e5 + 1;

ll cnt[MX];
void solve()
{
	int N; 
	ll K;
	cin >> N >> K;
	forn(1,i,N)
	{
		int a,b; cin >> a >> b;
		cnt[a] += b;
	}
	forn(1,i,MX)
	{
		if(K <= cnt[i])
		{
			cout << i;
			return;
		}
		K -= cnt[i];
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
