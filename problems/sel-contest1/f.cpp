#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
using namespace std;
typedef long long ll;
// typedef __int128_t bgl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main

ll getv(double x)
{
	if(x >= 440)
		return 12 * log2(x) - log2(440);
	else
		return 12 * log2(440) - log2(x);
}

void solve()
{
	int t;
	double a,b;
	cin >> t;
	ll x1, x2;
	ll res = 0;
	while(t--)
	{
		cin >> a >> b;
		x1 = getv(a);
		x2 = getv(b);
		res += abs(x1-x2);
	}
	cout << res;
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