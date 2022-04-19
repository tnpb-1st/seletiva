#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
// typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)

void solve()
{
	int t, n, s;
	cin >> t;
	while(t--)
	{
		cin >> n >> s;
		int median_i = ceil((float)n/2);
		int leftovers = n - median_i + 1;
		int median = s/leftovers;
		int remainder = s % leftovers;
		cout << median << endl;
	}

}

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	solve();
	return 0;
}