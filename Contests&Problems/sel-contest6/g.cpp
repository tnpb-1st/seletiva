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
ll dp[101][101];
const int MOD = 1000000;

void solve()
{
    for(int i = 1; i <= 100; i++){
        dp[1][i] = i;
        dp[i][1] = 1;
    }
    for(int i = 2; i <= 100; i++) {
        for(int j = 2; j<= 100; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
        }
    }
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	solve();
    int x, y;
    while(cin >> x >> y && (x!=0&&y!=0)) {
        cout << dp[x][y]<<endl;
    }
	return 0;
}
