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
	ll n, exp_sum, given_sum, num;
	n = exp_sum = given_sum = num = 0;
	cin >> n;
	exp_sum = ((1 + n) * (n))/2;
	for(int i=0; i < n-1; i++)
	{
		cin>>num;
		given_sum += num;
	}
	cout<< (ll)(exp_sum - given_sum)<<endl;

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