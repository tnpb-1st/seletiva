#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
#define inf LONG_LONG_MAX
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
ll parents[300069], dist[300069];
pair<ll,ll> edges[300069];
vll adj[300069], ans; 

void solve()
{
   int t, n,a, cc;
   cin >> t;
   while(t--) {
       cc = 1;
       stack<pii> S;
       cin >> n;
       int mx;
       for(int i = 1; i <=n ; i++) {
           cin >> a;
           if(S.size() == 0) {
               mx = a;
               S.push({mx,a});
               continue;
           }
           if(a < S.top().first) {
               S.push({mx, a});
            }
           else {
               cc++;
               while(S.size()) S.pop();
               S.push({a, a});
               mx = a;
           }
       }
       cout<<cc<<endl;
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
