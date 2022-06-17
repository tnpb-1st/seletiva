// Problem: Distinct Palindrome
// Contest: CodeChef - Starters 43 Division 4 (Rated)
// URL: https://www.codechef.com/START43D/problems/DISPAL
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
	map<int, char> mp;
	for(char i = 'a'; i <= 'z'; i++) {
		mp[i-'a' + 1] = i;
	}
	while(t--) {
		int n,k;cin>>n>>k;
		string hv1="", hv2="", mid="";
		if(k > 26) cout << - 1 << endl;
		else if(((n % 2) == 0) && (k > (n/2))) cout << -1 << endl;
		else if(((n % 2) != 0) && (k > ((n/2)+1))) cout << -1 << endl;
		else {
			if((n%2) == 0) {
				// k par
				for(int i = 1, j = 1; i <= (n/2); i++) {
					if(i < k)
						hv1 += mp[j++];
					else
						hv1 += mp[j];
				}
				hv2 = hv1;reverse(all(hv2));
				cout<<hv1<<hv2<<endl;
			} else {
				//k impar
				for(int i = 1, j = 1; i <= (n/2); i++) {
					if(i < k)
						hv1 += mp[j++];
					else
						hv1 += mp[j];
				}
				hv2 = hv1;reverse(all(hv2));
				mid += (k < ((n/2) + 1)) ? hv1.back() : mp[k];
				cout<<hv1<<mid<<hv2<<endl;
			}
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