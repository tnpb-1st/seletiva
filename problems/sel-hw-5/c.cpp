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
const int inf = 1e9;
const ll infl = 1e18;

void solve()
{
    int n, k, x;
    ll max_sum = 0;
    cin >> n >> k;
    vll A;
    for(int i = 0; i < n; i++) {
        cin >> x;
        A.pb(x);
    }
    vll dp(n, infl);
    dp[n-1] = 0;
    for(int i = n-1; i >= 0; i--) {
        for(int j = i +1; j < n && (j - i) <= k; j++) {
            dp[i] = min(dp[i], dp[j] + abs(A[j] - A[i]));
        }
    }
    cout << dp[0];
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	solve();
	return 0;
}
