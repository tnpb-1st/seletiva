#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
#define inf 1e18
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

void solve()
{
    int n, t;
    cin >> n >> t;
    vector<char> chd(n);
    for(int i = 0; i < n; i++) cin>>chd[i];
    for(int j = 1; j<= t; j++) {
        for(int i = 1; i < n; i++) {
            if(chd[i-1] == 'B' && chd[i] == 'G') {
                swap(chd[i-1],chd[i]);
                i++;
            }
        }
    }
    for(auto &c:chd)cout<<c;
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
