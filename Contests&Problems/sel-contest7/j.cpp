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

const ll MOD = 1e9 + 7;
bitset<10000> powers;

ll fPow(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>=1;
	}
	return ans;
}

void solve()
{
    int tests;cin>>tests;
    while(tests--) {
        ll n, k;
        cin >> n >> k;
        bitset<1000> powers(k);
        ll cont = 1;
        ll ans = 0;
        for(int i = 0, j = 0; j < powers.count(); i++) {
            ans = (ans%MOD + powers[i] * (cont % MOD))%MOD;
            cont*=n;
            cont%=MOD;
            if(powers[i] == 1) j++;
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
