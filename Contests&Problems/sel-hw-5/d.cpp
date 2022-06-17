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
const int inf = 1e9;
const ll infl = 1e18;

string longestCommonSubsequence(string &text1, string &text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        string ans = "";
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                    
                } else {
                    dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        int l1 = 0, l2 = 0;
        while(l1 < m && l2 < n) {
            if(text1[l1] == text2[l2]) {
                ans += text1[l1];
                l1++;l2++;
            } else {
                if(l1 < m && dp[l1][l2] == dp[l1+1][l2]) {
                    l1++;
                } else if(l2 < n && dp[l1][l2+1] == dp[l1][l2]) {
                    l2++;
                }
            }
        }
        return ans;
}

void solve()
{
    string t1, t2;
    cin >> t1 >> t2;
    cout << longestCommonSubsequence(t1, t2);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	solve();
	return 0;
}
