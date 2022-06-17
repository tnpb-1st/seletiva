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
const int arrLim = 1e6;
int dp[100001];
/*
SOLUTION BY tnpb
*/
vector<int> freqA;

bool isSubstrValid() {
    return (freqA[0] > 0) && (freqA[1] > 0) && (freqA[2] > 0);
}

bool checkSubseq(int sz, string &s) {
    freqA.assign(3, 0);
    int l = 0, r = sz;
    for(int i = 0; i < sz; i++) {
        freqA[s[i] - '1']++;
        if(isSubstrValid()) return true;
    }

    while(r < s.size()) {
        if(isSubstrValid()) return true;
        freqA[s[l++] - '1']--;
        freqA[s[r++] - '1']++;
    }
    return isSubstrValid();
}


void solve()
{
    int t;
    cin >> t;
    while(t--) {
        string s; cin >> s;
        int l = 0, r = s.size(), mid, ans = 0;
        while(l <= r) {
            mid = l + (r-l)/2;
            if(checkSubseq(mid, s)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
