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
ll dp[100] = {};

const ll mod = infl;
ll power(ll x, ll y)
{
	// 3^5 = 3^101
	ll res = 1;
	ll n = y;
	while(n)
	{
		if(n & 1)
			res = (res * x)%infl; //

		n >>=1; //
		x= (x*x)%infl; //
	}
	return res;
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    //2^26 = 67108864
    //2^27 = 134217728
    if(n>27) cout<<m;
    else cout << m % power(2, n);
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
