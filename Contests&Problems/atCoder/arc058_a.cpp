// Problem: C - Iroha's Obsession
// Contest: AtCoder - AtCoder Beginner Contest 042
// URL: https://atcoder.jp/contests/abc042/tasks/arc058_a
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

bool check(int v, set<char> &mys) {
    string s = to_string(v);
	for(auto &c : s) if(mys.find(c) != mys.end()) return false;
	return true;
}

void solve()
{
	int v, n;cin>>v>>n;
	set<char> myset;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		char c = '0' + x;
		myset.insert(c);
	}
	int k = v;
	while(!check(k, myset))
		k++;
	cout << k;
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