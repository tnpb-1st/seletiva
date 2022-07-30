// Problem: 11450 -  
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/external/114/11450.pdf
// Memory Limit: 1024 MB
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
const int mx = 1e6;
// N L O S NE SE SO NO
int dr[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};
//g++ -std=c++17 main.cpp -o main && time ./main
//g++ -std=c++17 -Wall main.cpp -o main && time ./main
int dp[201][21];
int M, C;
vvi items;

int knapsack(int cap, int idx)
{
	if(cap < 0) return 0;
	if(idx == C) return M - cap;
	if(dp[cap][idx] == -1) {
		int bestChoice = 0;
		for(int i = 0; i < (int)items[idx].size(); i++)
			bestChoice = max(bestChoice, knapsack(cap-items[idx][i], idx + 1));
		dp[cap][idx] = bestChoice;
	}
	return dp[cap][idx];
}

void solve()
{
  int TC; cin >>TC;
  while(TC--)
  {
  	cin >> M >> C;
  	items.assign(M, vi());
  	memset(dp, -1, sizeof(dp));
  	for(int i = 0; i < C; i++) {
  		int sz; cin >> sz;
  		items[i].resize(sz);
  		for(int j = 0; j < sz; j++)
  			cin >> items[i][j];
  	}
  	int ans = knapsack(M, 0);
  	if(ans) cout << ans << endl;
  	else cout << "no solution"<<endl;
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
