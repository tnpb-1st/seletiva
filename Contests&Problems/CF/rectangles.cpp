// Problem: A. Rectangles
// Contest: Codeforces - Topic Stream Mashup: Probability + Combinatorics
// URL: https://codeforces.com/gym/306143/problem/A
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
// char M[100][100];
int R, C;
// N L O S NE SE SO NO
int dr[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};

void solve()
{
	int m, n; cin >> m >> n;
	int x = 0, y = 0;
	int M[m][n];
	ll ans = 0;
	// rows
	for(int i = 0; i < m; i++)
	{
		x = 0, y = 0;
		for(int j = 0; j < n; j++)
		{
			cin >> M[i][j];
			if(M[i][j] == 1) x++;
			else y++;
		}
		ans += (1LL << x) - 1;
		ans += (1LL << y) - 1;
	}
	
	// cols
	for(int j = 0; j < n; j++)
	{
		x = 0, y = 0;
		for(int i = 0; i < m; i++)
		{
			if(M[i][j] == 1) x++;
			else y++;
		}
		ans += (1LL << x) - 1;
		ans += (1LL << y) - 1;
	}
	
	ans -= 1LL * m * n;
	cout << ans;
	
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
