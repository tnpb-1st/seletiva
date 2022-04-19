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
/*
SOLUTION BY tnpb
*/

void solve()
{
	int t;cin>>t;
    while(t--) {
        int n0,n1,n2;
        cin >> n0 >> n1 >> n2;
        string res = "";
        string t1 = "00", t2 = "10", t3 = "11";
        if(n1 == 0 && n0 != 0) {
            res += t1;
            for(int i = 2; i <= n0; i++) {
                res += '0';
            }
        } else if(n1 == 0 && n2 != 0) {
            res += t3;
            for(int i = 2; i <= n2; i++) {
                res += '1';
            }
        } else if(n1 != 0) {
            if(n0 >= 1) {
                res += t1;
                for(int i = 2; i <= n0; i++) {
                    res += '0';
                }
            }
            if(n0)n1--;
            if(n2)n1--;
            for(int i = 1; i <= ceil(n1/2.0); i++) {
                res += t2;
            }
            if(n2 >= 1) {
                res += t3;
                for(int i = 2; i <= n2; i++) {
                    res += '1';
                }
            }
            if(n1 % 2 == 0) res += '0';
        }
        cout<<res<<endl;
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
