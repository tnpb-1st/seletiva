#include <bits/stdc++.h>
using namespace std;
vector<long long> A;

void solve() {
    int t; cin >> t;
    while(t--) {
        int n; long long _min;cin>>n>>_min;
        A.resize(n);
        for(int i = 0; i < n; i++) cin >> A[i];
        sort(A.begin(), A.end());
        int ans=0;
        auto l = lower_bound(A.begin(), A.end(), _min);
        ans += (A.end() - l);
        long long tmp_sz = 0;
        long long low = _min - 1;
        for(auto itr = l-1; itr != A.begin() - 1; itr--) {
            if((tmp_sz % INT64_MAX) * low < _min) {
                low = *itr;
                tmp_sz++;
            }
            else {
                ans++;
                low = *itr;
                tmp_sz = 1;
            }
        }
        if((tmp_sz % INT64_MAX) * low >= _min) ans++;
        cout<<ans<<'\n';
    }
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
    // freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
    solve();
	return 0;
}
