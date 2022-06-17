// Problem: B. Make AP
// Contest: Codeforces - Codeforces Round #764 (Div. 3)
// URL: https://codeforces.com/contest/1624/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
const int INF = 0x3f3f3f3f;
const ll INFLL = 8e18;
const int mx = 1e6;
int dp[100001];
char M[100][100];
int R, C;
// N L O S NE SE SO NO
int dr[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};

void solve()
{
	int t; cin >> t;
	ll a,b,c;
	while(t--) {
		cin >> a >> b >> c;
		int na = b - (c-b);
		int nb = c - (c-a)/2;
		int nc = b + (b-a);
		if(na >= a && na % a == 0 && na != 0) {
			cout << "YES"<<endl;
		} else if(nb >= b && (c-a) % 2 == 0 && nb % b == 0 && nb != 0) {
			cout << "YES" << endl;
		} else if(nc >= c && nc % c == 0 && nc != 0) {
			cout << "YES"<<endl;
		} else {
			cout << "NO"<<endl;
		}
	}
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