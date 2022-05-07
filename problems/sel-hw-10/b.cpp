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
const ll infl = 1e10;
const int arrLim = 1e6;
int dp[100001];
/*
SOLUTION BY tnpb
*/
template<class T>
void printContainer(T &container) {
	for(auto &ele:container) cout << ele << ' ';
	cout<<'\n';
}

void solve()
{
    int n; cin >> n;
    multiset<ll> l,r;
    vector<pair<ll,ll>> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
        l.insert(points[i].first);
        r.insert(points[i].second);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        l.erase(l.find(points[i].first));
        r.erase(r.find(points[i].second));
        ans = max(ans, *r.begin() - *l.rbegin());
        l.insert(points[i].first);
        r.insert(points[i].second);
    }
    cout << ans << endl;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
