// Problem: C - Sequence
// Contest: AtCoder - AtCoder Beginner Contest 059
// URL: https://atcoder.jp/contests/abc059/tasks/arc072_a
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
	int n; cin >> n;
	ll ans1 = 0, ans2 = 0;
	ll A[n], P[n];for(int i = 0; i < n; i++) cin >> A[i];
	P[0] = A[0];
	// elementos pares positivos
	if(P[0] <= 0) ans1 += llabs(P[0]) + 1, P[0] = 1;
	for(int i = 1; i < n; i++) 
	{
		P[i] = P[i-1] + A[i];
		if((i % 2 == 0) && (P[i] <= 0)) {
			ans1 += (llabs(P[i]) + 1LL);
			P[i] = 1;
		}	else if ((i % 2 != 0) && (P[i] >= 0)) {
			ans1 += (1LL + P[i]);
			P[i] = -1;
		}
	}
	
	P[0] = A[0];
	// elementos pares negativos
	if(P[0] >= 0) ans2 += llabs(P[0]) + 1, P[0] = -1;
	for(int i = 1; i < n; i++) 
	{
		P[i] = P[i-1] + A[i];
		if((i % 2 == 0) && (P[i] >= 0)) {
			ans2 += (P[i] + 1LL);
			P[i] = -1;
		}	else if ((i % 2 != 0) && (P[i] <= 0)) {
			ans2 += (1LL + llabs(P[i]));
			P[i] = 1;
		}
	}
	cout << min(ans1,ans2);
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
