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
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int gcd_ext(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1, y = 0;
		return a;
	}
	int nx, ny;
	int gc = gcd_ext(b, a%b, nx, ny);
	x = ny;
	y = nx - (a/b) * ny;
	return gc;
}



void solve()
{
    int rick_b, rick_inc, mort_b, mort_inc;
    cin >> rick_inc >> rick_b >> mort_inc >> mort_b;
    int x,y;
    ll ans = -1;
    int have_ans = gcd_ext(rick_inc, mort_inc,x,y);
    if(!have_ans) {
        cout<<ans;
    }else {
        vll rick_times(1000), mort_times(1000);
        for(int i =0; i < 1000; i++) {
            rick_times[i] = rick_b + i * rick_inc;
            mort_times[i] = mort_b + i * mort_inc;
        }
        for(ll &ele:rick_times) {
            for(ll &ele2:mort_times) {
                if(ele == ele2) {
                    ans = ele;
                    goto ans;
                }
            }
        }
        ans:
        cout<<ans;
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
