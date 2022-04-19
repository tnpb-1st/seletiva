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

ll fastExp(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b&1)ans = ans * a % infl;
        a = a * a % infl;
        b >>=1;
    }
    return ans;
}


bool check(int x) {
    for(int i = 2; i*i <= x; i++) {
        for(int j = 2;fastExp(i,j) <= x; j++) {
            if(fastExp(i,j) == x) return true;
        }
    }
    return false;
}

void solve()
{
    int n;cin>>n;
    vi fav(n);
    for(int i = 0; i < n; i++) cin>>fav[i];
    if(n == 0) {
        if(check(fav[0]))
            cout<<fav[0]<<endl;
        else
            cout<<"NO CIVIL WAR"<<endl;
    } else {
        int ans = gcd(fav[0],fav[1]);
        for(int i = 2; i < n; i++) {
            ans = gcd(fav[i],ans);
        }
        if(check(ans)) {
            cout << ans << endl;
        }
        else {
            cout << "NO CIVIL WAR"<<endl;
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
