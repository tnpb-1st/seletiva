// Problem: I. Isabel's Divisions
// Contest: Codeforces - Treino 11-06-2022
// URL: https://codeforces.com/group/yc7Yxny414/contest/385417/problem/I
// Memory Limit: 256 MB
// Time Limit: 300 ms
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
	int n;string s;
	cin >> n;s = to_string(n);
	int ans = 0;
	for(int i = 1; i <= s.size(); i++) {
		int dig = 0 + (s[i-1] - '0');
		if(dig == 0) continue;
		if(n % dig == 0) ans++;
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