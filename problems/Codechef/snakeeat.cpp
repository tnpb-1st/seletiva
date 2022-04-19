#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)

ll BS(ll M, ll K, vector<ll>& prefixSum)
{
	auto getSum = [&](ll i, ll j)
	{
		if(i==0) return prefixSum[j];
		else return prefixSum[j] - prefixSum[i - 1];
	};
	ll start = 0, end = M;
	ll ans = 0;
	while(start <= end)
	{
		ll mid = start + (end-start)/2;
		ll req = (M - mid + 1) * K - getSum(mid, M);
		if(req <= mid)
		{
			ans = M - mid + 1;
			end = mid - 1;
		}else{
			start = mid + 1;
		}
	}
	return ans;
}

void solve()
{
	int T; cin >> T;
	while (T--)
	{
		ll N, Q;
		cin >> N >> Q;
		vector<ll> snkLens(N);
		for(ll i = 0; i < N; i++) cin >> snkLens[i];
		sort(snkLens.begin(), snkLens.end());
		vector<ll> prefixS(snkLens.begin(), snkLens.end());
		for(ll i = 1; i < N; i++) prefixS[i] += prefixS[i - 1];
	

		while(Q--)
		{
			ll ans = N;
			ll K; cin >> K;
			ll endIndex = upper_bound(snkLens.begin(), snkLens.end(), K-1) - snkLens.begin();
			ans -= endIndex;
			ans += BS(endIndex - 1, K, prefixS);
			cout<<ans<<endl;
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);

	solve();
		
	return 0;
}