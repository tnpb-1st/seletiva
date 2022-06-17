#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>
#define lli long long int
#define sf(a) scanf("%d", &a)
#define forn(i,n) for(int i = 0; i < n; ++i)
const int mx = 1e6+5;
const int inf = 0x3f3f3f3f;

using namespace std;

int rShift(int i, deque<int> &v){
	int cnt = 0;
	while(v.size() != i+1) v.pop_back();
	while(v.back() != i+1){
		v.push_front(v.back());
		v.pop_back();
		++cnt;
	}
	return (i+1) - cnt;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		deque<int> v(n), ans(n);
		for(int i = 0; i < n; i++) cin >> v[i];
		for(int i = n-1; i >= 0; --i){
			if(v[i] != i+1){
				ans[i] = rShift(i,v);
			}
		}
		for(int i = 0; i < n; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}