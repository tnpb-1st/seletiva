// Problem: D. The Clock
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/D
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

bool checkPal(string &s) {
	for(int i = 0, j = s.size()-1; i<=j; i++,j--)
		if(s[i]!=s[j]) return false;
	return true;
}

void solve()
{
	int t;cin >> t;
	while(t--) {
		string t0;cin>>t0;
		int cyc,ans=0;cin >> cyc;
		int h,mm;
		h = cyc/60;
		mm = cyc%60;
		set<string> mset;
		mset.insert(t0);
		string x = "";
		bool cond = true;
		while(cond) {
			int hx, mx;
			hx = stoi(t0.substr(0,2));
			mx = stoi(t0.substr(3));
			mx += mm;
			hx += (mx/60) + h;
			mx%=60;
			hx%=24;
			x = "";
			if(hx < 10) x += '0';
			x+=to_string(hx) + ':';
			if(mx < 10) x += '0';
			x += to_string(mx);
			if(mset.count(x))cond = false;
			mset.insert(x);
			t0 = x;
		}
		for(auto tt = mset.begin(); tt != mset.end(); tt++) {
			string k = *tt;
			if(checkPal(k)) ans++;
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