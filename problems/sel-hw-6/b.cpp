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

int gcd(int a, int b) {
    while(b) a%=b, swap(a,b);
    return a;
}

int maxGCD(int &R) {
    int ans = 1;
    for(int i = R/2; i>= 1; i--) {
        if((R/i) > 1) {
            ans = i;
            break;
        }
    }
    return ans;
}

void solve()
{
    int t;
    cin >> t;
    while(t--) {
        int r;
        cin >> r;
        cout << maxGCD(r)<<endl;
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
