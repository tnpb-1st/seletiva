// Problem: Problem 1. Shell Game
// Contest: USACO - USACO 2019 January Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=891
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define forn(x) for(int i = 1; i<=x; i++)
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

void solve()
{
	int n,ans; cin >> n;
	vi shellP(n+1), counter(n+1, 0);
	forn(3) shellP[i]=i; 
	for(int i = 0; i < n; i++) {
		int a,b,g;cin>>a>>b>>g;
		swap(shellP[a],shellP[b]);
		counter[shellP[g]]++;
	}
	ans = max({counter[1],counter[2],counter[3]});
	cout << ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("shell.in", "r", stdin);
		freopen("shell.out", "w", stdout);
    solve();
    return 0;
}