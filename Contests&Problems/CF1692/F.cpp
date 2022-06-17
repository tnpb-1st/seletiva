// Problem: F. 3SUM
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/F
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
	int t; cin >> t;
	while(t--) {
		bool possible = false;
		vi F(10, 0), D;
		int n; cin >> n;
		for(int i = 0; i < n; i++) {
			ll x; cin >> x;
			int d = x % 10;
			if(F[d] >= 3) continue;
			F[d]++;
			D.pb(d);
		}
		int lim = D.size();
		for(int i = 0; i < lim; i++)
			for(int j = i + 1; j < lim; j++)
				for(int k = j + 1; k < lim; k++)
					if( (D[i] + D[j] + D[k]) % 10 == 3 ) {
						possible = true;
						goto output;
					}
		
		output:
		if(possible) cout << "YES" << endl;
		else cout << "NO" << endl;
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