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

void solve()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi C(5, 0);
        int total_letters = 0;
        string s;
        for(int i = 0; i < n; i++) {
            cin >> s;
            for(auto &c:s) {
                C[c-'a']++;
                total_letters++;
            }
        }
    }

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
