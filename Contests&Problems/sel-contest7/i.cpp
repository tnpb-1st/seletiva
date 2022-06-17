#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
const int inf = 1e9;
const ll infl = 1e18;
/*
SOLUTION BY tnpb
*/

void solve()
{
    int n; ll r_time;
    cin >> n >> r_time;
    int books[n];
    for(int i = 0; i < n; i++) {
        cin >> books[i];
    }
    int ans = 0;
    int cont = 0;
    ll rt = 0;
    for(int i = 0; i < n; ++i) {
        for (;cont < n && rt + books[cont] <= r_time;cont++)
            rt += books[cont];

        ans = max(ans, cont - i);
        rt -= books[i];
    }
    cout<<ans;
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
