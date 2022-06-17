// Problem: C. Division by Two and Permutation
// Contest: Codeforces - Codeforces Round #764 (Div. 3)
// URL: https://codeforces.com/contest/1624/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
	int t,n; cin >> t;
	while(t--) {
		cin >> n;
		vll A(n);
		set<ll> myset;
		for(ll i = 1LL; i <= n; i++) {
			myset.insert(i);
			cin >> A[i-1];
		}
		bool found = true;
		for(auto x : A) {
			if(myset.find(x) != myset.end()) {
				myset.erase(x);
			}else {
				while(x != 0 && myset.find(x) == myset.end()) {
					x/=2;
				}
				if(x == 0) {
					found = false;
					break;
				} else {
					myset.erase(x);
				}
			}
		}
		if(found) cout << "YES" << endl;
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