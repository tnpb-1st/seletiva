// Problem: C - Sentou
// Contest: AtCoder - AtCoder Beginner Contest 060
// URL: https://atcoder.jp/contests/abc060/tasks/arc073_a
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
	int n; ll T; cin >> n >> T;
	ll ans = T;
	vll A(n);
	for(auto &x: A) cin >> x;
	reverse(all(A));
	for(int i = 1; i < n; i++) {
		if((A[i-1] - A[i]) < T) ans += llabs(A[i] - A[i-1]);
		else ans += T;
	}
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
