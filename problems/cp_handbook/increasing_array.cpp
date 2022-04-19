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
	int N;""
	ll num, dif;
	ll sum = 0;
	cin>>N;
	ll arr[N];
	cin>>arr[0];
	for(int i=1; i<N; i++)
	{
		cin>>arr[i];
		if(arr[i] < arr[i-1])
		{
			dif = arr[i-1] - arr[i];
			sum += dif;
			arr[i] += dif;
		}
	}
	cout<<sum;
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