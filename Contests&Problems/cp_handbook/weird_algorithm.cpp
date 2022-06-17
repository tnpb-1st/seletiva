#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)

void rec(ll n)
{
	if (n == 1)
	{
		cout<<1;
		return;
	}
	else
	{
		cout<<n<<' ';
		if(n & 1)// odd
			return rec((ll)(n*3 + 1));
		else
			return rec(n/2);
	}
}

void solve()
{
	ll numb;
	cin>>numb;
	rec(numb);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freeopen("input.txt", "r", stdin);
	// freeopen("output.txt", "w", stdout);

	solve();
	return 0;
}