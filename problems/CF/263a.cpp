#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)

void solve()
{
	int l0, c0, n;
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cin >> n;
			if(n == 1)
			{
				l0 = i;
				c0 = j;
			}
		}
	}
	cout << abs(l0 - 2) + abs(c0 - 2) << endl;
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