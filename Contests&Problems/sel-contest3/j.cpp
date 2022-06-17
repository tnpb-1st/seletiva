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

void solve()
{
    int n;
	cin >> n;
	vector<ll> A(n), B(n), C(n);
    ll x;
	for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    for(int i = 0; i < n; i++)
    {
        C[i] = A[i] - B[i];
    }
	sort(all(C));
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (C[i] <= 0) continue;
		int bound = lower_bound(C.begin(), C.end(), -C[i] + 1) - C.begin();
		ans += (i-bound);
	}
	
	cout << ans << endl;
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
