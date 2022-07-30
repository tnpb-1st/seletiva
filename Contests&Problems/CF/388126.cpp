// Problem: C. Palindrome Again !!
// Contest: Codeforces - 2 de Julho - div 2
// URL: https://codeforces.com/group/yc7Yxny414/contest/388126/problem/C
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
author: eiji_tnpb
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define REP(idx,x) for(int i = idx; i<x; i++)
#define REPN(idx,x) for(int i = idx; i<=x; i++)
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
const int mx = 1e5 + 1;
int dp[100001];
char M[100][100];
int R, C;
// N L O S NE SE SO NO
int dr[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};
vector<char> S(mx);
int N, P;

int dif(char c1, char c2)
{
	int x = min(c1,c2), y = max(c1,c2);
	int cost1 = y-x;
	int cost2 = (x-'a') + ('z' - y);
	return min(cost1,cost2);
}

void solve()
{
	int T; cin >> T;
	while(T--)
	{
		cin >> N >> P;P--;
		for(int i = 0; i< N; i++) cin >> S[i];
		ll ans = 0;
		int lL = mx, rL = -1;
		for(int i = 0; i < N/2; i++)
		{
			char a = S[i], b = S[N-i-1];
			if(a!=b)
			{
				if(a > b) swap(a,b);
				ans += min(b-a,a-b+26);
				lL = min(lL,i);
				rL = max(rL, i);
			}
		}
		if(lL == mx)
		{
			cout << 0 << endl;
			continue;
		}
		if(P > N/2) P = N - 1 - P;
		ans += min(abs(P-lL), abs(P-rL));
		ans += (rL-lL);
		cout << ans << endl;
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
