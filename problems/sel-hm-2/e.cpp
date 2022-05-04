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
const int arrLim = 1e6;
int dp[100001];
/*
SOLUTION BY tnpb
*/
const ll MOD = infl;
bool checkValue(ll x, ll m, ll &n, ll &k) {
    m = m - x;
    ll a0 = x - 1;
    ll r = n-k; // valores a direita de k
    ll l = k - 1; // valores à esquerda de k
    ll r_pillows = (r * (a0 + a0 - r  + 1) )/2;
    if(a0 < r) {
        r_pillows = (a0 * (a0 + 1) / 2) + (r-a0);
    }
    ll l_pillows = (l * (a0 + a0 - l + 1) )/2;
    if(a0 < l) {
        l_pillows = (a0 * (a0+1)/2) + (l - a0);
    }
    if(r_pillows + l_pillows <= m) return true;
    return false;
}


void solve()
{  
    ll n,m, k;
    cin >> n >> m >> k;
    ll l = 1, r = m - n + 1, mid, ans;
    while(l <= r) {
        mid = l + (r-l)/2;
        if(checkValue(mid, m, n, k)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
