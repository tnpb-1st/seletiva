// Problem: B - Checkpoints
// Contest: AtCoder - AtCoder Beginner Contest 057
// URL: https://atcoder.jp/contests/abc057/tasks/abc057_b
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
// char M[100][100];
int R, C;
// N L O S NE SE SO NO
int dr[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};
int N,M;
vpii students, checkpoints;

int getDist(int &i, int &j) {
	pii s = students[i], c = checkpoints[j];
	return (abs(s.first - c.first) + abs(s.second - c.second));
}

void solve()
{
	cin >> N >> M;
	students.resize(N+1);checkpoints.resize(M+1);
	vector<int> ans(N, INF);
	for(int i = 1; i <= N; i++) {
		int x,y;cin>>x>>y;
		students[i] = {x,y};
	}
	for(int i = 1; i<= M; i++) {
		int x,y;cin>>x>>y;
		checkpoints[i] = {x,y};
	}
	for(int i = 1; i<= N; i++) {
		int d = INF;
		for(int j = 1; j <= M; j++) {
			if(getDist(i, j) < d) {
				d = getDist(i,j);
				ans[i-1] = j;
			}
		}
	}
	for(auto &x: ans)cout << x << endl;
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