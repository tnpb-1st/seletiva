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

vector<pii> get_primes(int n) {
	vector<pii> primes;
	for(int p = 2; p * p <= n; ++p) {
		if(n % p == 0) {
			int exp = 0;
			while(n % p == 0) {n /= p; ++exp;}
			primes.emplace_back(p,exp);
		}
	}
	if(n > 1) primes.emplace_back(n, 1);
	return primes;
}

void solve()
{
    int t;
    cin >> t;
    for (int i = 1; i<=t; i++) {
        int n;
        cin >> n;
        vector<pii> ans = get_primes(n);
        cout << "Case "<<i<<":";
        for(auto &x:ans)cout<<' ' << x.first;
        cout<<endl;
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
