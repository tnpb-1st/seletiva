// Problem: D. Muitos TLEs
// Contest: Codeforces - UFPE Starters Final Try-Outs 2022
// URL: https://codeforces.com/group/A0ugc1djC6/contest/103726/problem/D
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

int kmin(vll &arr, int &n, ll &k) {
	int start = 0, end = 0, sum = arr[0], count = 0;
	while(start < n && end < n) {
		if(sum < k) {
			end++;
			if(end < start)
				count +=  end - start;
			if(end < n)
				sum += arr[end];
		} else {
			sum -= arr[start];
			start++;
		}
		return count;
	}
}

void solve()
{
	int n; ll k;
	cin >> n >> k;
	vll A(n);for(auto &x : A) cin >> x;
	ll res = ((ll)n*(n+1)) >> 1;
	cout << res - kmin(A, n, k);
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