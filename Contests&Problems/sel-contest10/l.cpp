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


/*
SOLUTION BY tnpb
*/
// sieve
void segmentedSieve(ll n, vector<bool> &is_prime) {
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; (ll)i * i <= n; i++) {
        if (is_prime[i]) {
            for (ll j = (ll)i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}


void get_divisors(ll n, vector<bool> &is_prime, vvll &divisors) {
    if(!is_prime[n]) return;
    for(ll i = 1; (ll)i * i <= n; ++i) {
        if(!is_prime[i])continue;
        if(n % i == 0) {
            if(is_prime[i] && i != n) divisors[n].push_back(i);
            if(n/i != i && is_prime[n/i] && (n/i != n)) divisors[n].push_back(n/i);
        }
    }
}
//

void solve()
{
    vector<bool> is_prime(100002, true);
    const ll lim = 100002;
    segmentedSieve(lim, is_prime);

    ll n;cin>>n;
    ll colors[n+1];
    ll color = (n < 3) ? 1 : 2;
    ll color_p = 1;
    string ans = "";
    for(ll i = 2; i <= n+1; i++) {
        if(is_prime[i]) colors[i-1] = color_p;
        else colors[i-1] = 2;
        ans += to_string(colors[i-1]) + ' ';
    }
    cout<<color<<endl;
    cout<<ans;
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
