#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
typedef vector<bool> vbool;
typedef pair<int,int> pii;
// typedef __int128_t bgl;
// range of int valu'es -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main

void solve()
{
    int n;
    cin >> n;
    vll dif(n+1);
    ll clw, killer_diff, alive = 0, max_diff = INT_MAX;
    for(ll i = 1; i <= n; i++) {
        cin >> clw; killer_diff = i - clw;
        dif[i] = killer_diff;      
    }
    
    for(ll k = n; k >= 1; k--) {
        if(k >= max_diff) {
            alive++;
        }
        if(dif[k] < max_diff) max_diff = dif[k];
    }
    cout<<n - alive;
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
