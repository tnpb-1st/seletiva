// Problem: Make them Equal
// Contest: CodeChef - START43
// URL: https://www.codechef.com/submit-v2/MAKEQUAL
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define forn(x) for(int i = 1; i<=x; i++)
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
	int tc; cin >> tc;
	while(tc--) {
		int a, b, c;
		cin >> a >> b >> c;
		ll bit = 1;
		bool flag = true;
		
		for(int i = 0; i <= 30; i++) {
			if(a == b && b == c) break;
			
			bit = (1 << i);
			int cnt = 0;
			cnt = ((a & bit) != 0) + ((b & bit) != 0) + ((c & bit) != 0);
			
			if(cnt == 0 || cnt == 3)
			{
				flag = false;
				break;
			}
			else if(cnt == 1)
			{
				if(a & bit) a += bit;
				else if(b & bit) b += bit;
				else c += bit;
			}
			else 
			{
				if((a & bit) == 0) a += bit;
				else if((b & bit) == 0) b += bit;
				else c += bit;
			}
		}
		if(flag && (a == b) && (b == c))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
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
