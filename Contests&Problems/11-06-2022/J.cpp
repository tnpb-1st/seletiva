// Problem: J. Jeffrey's ambition
// Contest: Codeforces - Treino 11-06-2022
// URL: https://codeforces.com/group/yc7Yxny414/contest/385417/problem/J
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
	int k, n, p = 0, buy = 0; cin >> k >> n;
	bool A[n] = {};
	while(k--) {
		int j;cin >> j;
		if(j)p++;
		for(int i = 0; i < j; i++) {
			int x;cin>>x;
			A[x-1] = 1;
		}
	}
	for(int i = 0; i < n && p > 0;i++) {
		if(A[i]) p--,buy++;
	}
	cout << n - buy;
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