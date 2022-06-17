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
const int arrLim = 1e6;
int dp[100001];
int parents[200001];
/*
SOLUTION BY tnpb
*/

void solve()
{
    int n,u,v;cin>>n;
    parents[1] = -1;
    for(int i = 2; i<= n; i++) {
        cin >> u;
        parents[i] = u;
    }
    stack<int> path;
    u = n;
    while(u != -1) {
        path.push(u);
        u = parents[u];
    }
    while(path.size()) {
        cout << path.top() << ' ';
        path.pop();
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
