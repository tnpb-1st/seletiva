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
    map<char,string> M;
    set<string> dict;
    for(char c1 = 'a'; c1 <= 'z'; c1++) {
        for(char c2 = 'a'; c2 <= 'z'; c2++) {
            if(c1 == c2) continue;
            string s = "";
            s.push_back(c1);
            s.push_back(c2);
        }
    }
    // int t;
    // cin >> t;
    // while(t--) {
    //     string s; cin >> s;
    //     auto k = to_string((int)s[0]) + to_string((int)s[1]);
    //     auto ans = distance(dict.begin(),dict.lower_bound(sear));
    //     cout << ans + 1<< endl;
    // }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
