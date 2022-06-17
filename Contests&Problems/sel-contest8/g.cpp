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

ll spa(ll an) 
{
    return ((1 + an) * an) >> 1;
}

ll rev_spa(ll n, ll &k) {
    ll x = k - n;
    return ((x+(k-1))*(k-1-x)) >> 1;
}

void solve()
{
	int t;
    cin >> t;
    while(t--) {
        ll k,lim;
        cin >> k >> lim;
        ll max_emotes = k * (k-1) + k;
        ll l=1,r=1 + 2*(k-1),mid, ans = 2*(k-1)+1, num_emotes;
        while(l <= r) {
            mid = l + (r-l)/2;
            if(mid >= k) {
                num_emotes = spa(k);
                num_emotes += spa(k-1);
                num_emotes -= spa(2*k-1-mid);
            } else {
                num_emotes = spa(mid);
            }
            if(num_emotes >= lim) {
                ans = mid;
                r = mid -1;
            } else {
                l = mid + 1;
            }
        }
        cout<< ans << endl;
    }
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
    
	solve();
	return 0;
}
