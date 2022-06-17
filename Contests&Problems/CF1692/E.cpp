// Problem: E. Binary Deque
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

ll query(int l, int r, vll &vec) {
	return vec[r] - (l ? vec[l-1] : 0);
}

void solve()
{
	int t;cin >> t;
	while(t--) {
		int n, s; cin >> n >> s;
		vll A(n), P(n);
		for(int i = 0; i < n; i++) {
			cin >> A[i];
			P[i] = A[i];
			if(i) P[i] += P[i-1];
		}
		int ans = INF;
		for(int i = 0; i < n; i++) {
			int l = i, r = n-1, pos = -1, mid;
			while(l <= r) {
				mid = l + ((r-l) >> 1);
				if(query(i, mid, P) <= s) {
					pos = mid;
					l = mid + 1;
				} else r = mid - 1;
			}
			if(pos == -1 || query(i, pos, P) != s) continue;
			ans = min(ans, n - (pos - i + 1));
		}
		cout << (ans == INF ? -1 : ans) << endl;
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