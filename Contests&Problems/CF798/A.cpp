// Problem: A. Lex String
// Contest: Codeforces - Codeforces Round #798 (Div. 2)
// URL: https://codeforces.com/contest/1689/problem/A
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
	// 6 4 2
	// aaaaaa
	// bbbb
	int t;cin>>t;
	while(t--) {
		int m, n , k;
		string a,b, c = "";
		cin >> m >> n >> k;
		cin >> a >> b;
		sort(all(a));sort(all(b));
		int sa = 0, sb = 0,  ka = 0, kb = 0;
		while(sa < m && sb < n) {
			if(ka < k && a[sa] < b[sb] || kb >= k) {
				c += a[sa++];
				ka++;
				kb = 0;
			} else {
				c+= b[sb++];
				kb++;
				ka = 0;
			}
		}
		cout << c << endl; 
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