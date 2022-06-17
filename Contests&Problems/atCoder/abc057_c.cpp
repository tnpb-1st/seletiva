// Problem: C - Digits in Multiplication
// Contest: AtCoder - AtCoder Beginner Contest 057
// URL: https://atcoder.jp/contests/abc057/tasks/abc057_c
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

int countDigits(ll num) {
	int dig = 0;
	while(num > 0){
		num/=10;
		dig++;
	}
	return dig;
}


void solve()
{
	ll N; cin >> N;
	if(N == 1){
		cout << 1;
		return;
	}
	int ans = countDigits(N);
	for(ll i = 1LL; i*i <= N; i++)
	{
		if(N%i != 0)continue;
		const ll B = N/i;
		const int cur = max(countDigits(i), countDigits(B));
		if(cur < ans) ans = cur;
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