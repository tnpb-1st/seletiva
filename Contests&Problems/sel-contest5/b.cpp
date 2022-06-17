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
// typedef __int128_t bgl;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main
const int inf = 1e9;
const ll infl = 1e18;

ll func(ll &a, ll &x) {return ((x/a) + (x % a));}

void solve()
{
    int t;
    ll l, r, a , mid;
    cin >> t;
    while(t--) {
        cin >> l >> r >> a;
        ll max_v = -1;
        if(l/a == r/a) {
            max_v = func(a,r);
        } else {
            mid = r - (r%a) - 1;
            max_v = max(func(a,mid),func(a,r));
        }
        cout<<max_v<<endl;
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
