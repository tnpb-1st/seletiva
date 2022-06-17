// Problem: B. Festa de Gap
// Contest: Codeforces - UFPE Starters Final Try-Outs 2022
// URL: https://codeforces.com/group/A0ugc1djC6/contest/103726/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	vi Ax(n), Ay(n), A, B;
	for(int i = 0; i < n; i++) cin >> Ax[i] >> Ay[i];
	A = Ax, B = Ay;
	sort(all(Ax));sort(all(Ay));
	int m = n/2;
	ll mx = Ax[m], my = Ay[m];
	if(n % 2 == 0) {
		mx = (mx + Ax[m-1]) >> 1, my = (my + Ay[m-1]) >> 1;
	}
	ll dist = 0;
	for(int i = 0; i < n; i++) {
		dist += abs(A[i] - mx) + abs(B[i] - my);
	}
	cout << dist;
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