// Problem: K. Kilo Waste
// Contest: Codeforces - Treino 11-06-2022
// URL: https://codeforces.com/group/yc7Yxny414/contest/385417/problem/K
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
	int k, n;
	cin >> k >> n;
	vi A(n);
	for(auto &x:A)cin>>x;
	sort(all(A));
	while(k--) {
		int d,res = 0, alt = INF; cin >> d;
		while(d > 0) {
			int local = INF;
			for(auto itr = A.begin(); itr != A.end(); itr++) {
				if(d >= (*itr)){
					int o = d % (*itr);
					local = min(local, o);
					if(o >= A[0]) alt = min(alt, o);
				} else {
					local = min(local, (*itr) - d);
				}
			}
			if(local == 0) {
				d = 0;
				break;
			} else {
				if(alt != INF) {
					d = alt;
					alt = INF;
				} else {
					res = local;
					d = 0;
				}
			}
		}
		cout << res << endl;
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