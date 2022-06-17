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
/*
SOLUTION BY tnpb
*/

void solve()
{
	int t;
    cin >> t;
    while(t--) {
        ll n, k,ans;
        cin >> n >> k;
        if(n%2==0) {
            if(k%n==0) ans = n;
            else ans = k % n; 
        } else {
            ll pos = n>>1;
            ll x = (k-1)/pos;
            ll y = (x+k) % n;
            ans = (y == 0) ? n : y;
        }
        cout<<ans<<endl;
    }
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
