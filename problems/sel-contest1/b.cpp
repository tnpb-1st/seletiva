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
	vi A(n);
	int l , r, l_a, r_a, k, ans = -1;
	l = r = l_a = r_a = 0;
	for(int i=0; i < n; i++)
	{
		cin >> k;
		A[i] = k;
		if(k)
			r++;
		else
			l++;
	}
	for(int i = 0; i < n; i++)
	{
		if(A[i])
			r_a++;
		else
			l_a++;
		if(r_a == r || l_a == l)
		{
			ans = ++i;
			break;
		}
	}
	cout << ans << endl;
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