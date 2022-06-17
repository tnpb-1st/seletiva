// Problem: Permutation AND
// Contest: CodeChef - Starters 43 Division 4 (Rated)
// URL: https://www.codechef.com/START43D/problems/PERMAND
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		if(n == 1) {
			cout << "1\n1" << endl;
		}else if(n % 2 == 0) {
			string s1="",s2="";
			for(int i = 1, j = n; i <= n; i++,j--) {
				s1 += to_string(i) + ' ';
				s2 += to_string(j) + ' ';
			}
			cout << s1 << endl << s2 << endl;
		}else {
			cout << -1 << endl;
		}
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