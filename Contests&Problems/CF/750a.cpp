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
	int n, k, ans = 0;
	cin >> n >> k;
	vector<int> A(n);
	A[0] = 5;
	for(int i =1; i < n; i++)
	{
		A[i] = (i+1) * 5 + A[i - 1];
	}
	int l = 0, mid, r = n - 1;
	while(l <= r)
	{
		mid = l + (r - l)/2;
		if(k + A[mid] <= 240)
		{
			ans = mid + 1;
			l = mid + 1;
		}else {
			r = mid - 1;
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