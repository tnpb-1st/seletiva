// Problem: B - Comparison
// Contest: AtCoder - AtCoder Beginner Contest 059
// URL: https://atcoder.jp/contests/abc059/tasks/abc059_b
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
	string A, B; cin >> A >> B;
	if(A.size() < B.size()) {
		cout << "LESS";
	} else if(A.size() > B.size()) {
		cout << "GREATER";
	}else {
		for(int i = 0; i < (int)A.size(); i++) {
			if(A[i] > B[i]) {
				cout << "GREATER";
				return;
			}else if (A[i] < B[i]) {
				cout << "LESS";
				return;
			}
		}
		cout << "EQUAL";
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