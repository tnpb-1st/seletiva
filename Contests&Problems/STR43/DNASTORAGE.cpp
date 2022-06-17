// Problem: DNA Storage
// Contest: CodeChef - Starters 43 Division 3 (Rated)
// URL: https://www.codechef.com/START43C/problems/DNASTORAGE
// Memory Limit: 256 MB
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
	map<string,char> mp;
	mp["4848"] = 'A', mp["4849"] = 'T', mp["4948"] = 'C', mp["4949"] = 'G';
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;string ans = "", s, ss;
		cin >> ss;
		for(int i = 0; i< ss.size(); i+=2) {
		    s = "";
			s.append(to_string(ss[i]));
            s.append(to_string(ss[i+1]));
			ans += mp[s];
		}
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