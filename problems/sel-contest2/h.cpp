#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
using namespace std;
typedef long long ll;
// typedef __int128_t bgl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main
ll get_val(ll &i,ll &k ,vector<ll> &S)
{
    if(i < k) return S[k-1];
    return S[i] - S[i - k];
}


void solve()
{
	ll n, k, x;
    cin >> n >> k;
    vector<ll> A, S(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> x;
        A.pb(x);
    }
    S[0] = A[0];
    for(ll j = 1; j < n; j++)
    {
        S[j] = S[j-1] + A[j];
    }
    ll ans = k-1;
    for(ll i = k; i < n; i++)
    {
        // ll a, b;
        // a = get_val(i,k,S), b = get_val(ans,k,S);
        if(get_val(i, k, S) < get_val(ans, k, S)) ans = i;
    }
    ans = ans - k + 2;
    cout<< ans<<endl;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	solve();
	return 0;
}