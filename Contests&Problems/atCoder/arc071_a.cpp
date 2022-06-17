// Problem: C - Dubious Document
// Contest: AtCoder - AtCoder Beginner Contest 058
// URL: https://atcoder.jp/contests/abc058/tasks/arc071_a
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
int M[51][26] = {};
int R, C;
// N L O S NE SE SO NO
int dr[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};

void solve()
{
	int n; cin >> n;
	string ans = "";
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		for(auto &c: s) M[i][c - 'a']++;
	}
	for(char j = 'a'; j <= 'z'; j++) {
		int num = INF;
		for(int i = 0 ; i < n; i++) {
			num = min(num, M[i][j - 'a']);
		}
		for(int i = 0; i < num; i++) {
			ans += j; 
		}
	}
	cout << ans;
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