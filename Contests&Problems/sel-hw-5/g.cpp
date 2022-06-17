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
    int n;
    while(cin >> n && n) {
        int maxS = 0,x;
        vi ans;
        for(int i = 0; i < n; i++) {
            cin >> x;
            if(x != 0) {
                maxS+=x;
                ans.pb(x);
            } 
        }
        if(maxS == 0) {cout << 0 << endl;}
        else {
            for(auto it = ans.begin(); it != ans.end(); it++) {
                if(it != (ans.end() - 1)) cout << *it << ' ';
                else cout << *it<<endl;
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
