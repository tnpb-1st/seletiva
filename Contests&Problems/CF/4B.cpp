// Problem: B. Before an Exam
// Contest: Codeforces - Codeforces Beta Round #4 (Div. 2 Only)
// URL: https://codeforces.com/contest/4/problem/B
// Memory Limit: 64 MB
// Time Limit: 500 ms
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
	int d, sumTime; cin >> d >> sumTime;
	vector<pii> days;
	int maxHours = 0, minHours = 0;
	for(int i = 0; i < d; i++) {
		int minH, maxH; cin >> minH >> maxH;
		maxHours += maxH;minHours += minH;
		days.pb({minH, maxH});
	}
	if(maxHours < sumTime || minHours > sumTime) {
		cout << "NO";
	} else {
		cout << "YES" << endl;
		sumTime -= minHours;
		for(auto &[l,r] : days) {
			int tmp = min(r - l, sumTime);
			sumTime -= tmp;
			cout << l + tmp << ' ';
			if(l == days.back().first && days.back().second == r) cout << endl;
		}
	}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
