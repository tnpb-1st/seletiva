// Problem: C - Chocolate Bar
// Contest: AtCoder - AtCoder Beginner Contest 062
// URL: https://atcoder.jp/contests/abc062/tasks/arc074_a
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
	ll H, W, ans = INF, ha, hb, hc, wa, wb, wc, Aa, Ab, Ac, cur;
	cin >> H >> W;
	for(ha = 1; ha < H; ha++)
	{
		Aa = ha*W;
		// case 1
		hb = floor((H-ha)/2.0), hc = ceil((H-ha)/2.0);
		Ab = hb*W, Ac = hc * W;
		cur = max({Aa,Ab,Ac}) - min({Aa,Ab,Ac});
		if(cur == 0)
		    int c = 2;
		ans = min(ans,cur);
		// case 2
		wb = floor(W/2.0), wc = ceil(W/2.0);
		Ab = (H-ha) * wb, Ac = (H-ha) * wc;
		cur = max({Aa,Ab,Ac}) - min({Aa,Ab,Ac});
		if(cur == 0)
		    int c = 2;
		ans = min(ans,cur);
	}
	
	for(wa = 1; wa < W; wa++)
	{
		Aa = H * wa;
		// case 3
		wb = floor((W-wa)/2.0), wc = ceil((W-wa)/2.0);
		Ab = H * wb, Ac = H * wc;
		cur = max({Aa,Ab,Ac}) - min({Aa,Ab,Ac});
		if(cur == 0)
		    int c = 2;
		ans = min(ans,cur);
		// case 4
		hb = floor(H/2.0), hc = ceil(H/2.0);
		Ab = (W-wa) * hb, Ac = (W-wa) * hc;
		cur = max({Aa,Ab,Ac}) - min({Aa,Ab,Ac});
		if(cur == 0)
		    int c = 2;
		ans = min(ans,cur);
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
