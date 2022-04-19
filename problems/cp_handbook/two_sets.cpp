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

void solve()
{
	int n;
	cin >> n;
	ll sum = ((1LL + n) * n)/2;
	if(sum % 2 != 0)
	{
		cout << "NO";
	}
	else
	{
		ll hl1, hl2;
		hl1 = hl2 = sum/2LL;
		vll v1, v2;
		for(int i = n; i > 0; i--)
		{
			if(hl2 >= i)
			{
				hl2 -= i;
				v2.pb(i);
			}
			else if(hl1 >= i)
			{
				hl1 -= i;
				v1.pb(i);
			}
		}
		// sort(v1.begin(), v1.end());
		// sort(v2.begin(), v2.end());
		cout<<"YES"<<endl;
		cout << v1.size() << endl;
		for(auto &x : v1)
			cout << x << " ";
		cout << endl;
		cout << v2.size() << endl;
		for(auto &x : v2)
			cout << x << " ";
	}
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