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

const ll maxn = 2e5 + 5;
const ll mod = 1000000007;
vector<ll> fat(maxn);


ll powmod(ll a, ll b, ll p){
    if (a == 0) return 0;
    ll product = 1;
    while(b > 0){
        if (b&1)    
            product = product * a % p;
        a = a * a % p;
        b >>= 1;    
    }
    return product;
}

ll inv(ll a, ll p){
    return powmod(a, p-2, p);
}

ll nCk(ll n, ll k, ll p){
    if(n < 0 || k < 0 || p < 0) return 0;
    if(n < k) return 0;
    else if(n == k) return 1;
    if(k == 1) return n;
    return ((fat[n] * inv(fat[k], p) % p) * inv(fat[n-k], p)) % p;
}

void solve()
{
    fat[0] = fat[1] = 1;
    for(int i = 2; i < maxn; i++) 
        fat[i] = ((fat[i-1] % mod )* i) % mod;
    int t; cin >> t;
    while(t--) {
        int n, k, x;
        cin >> n >> k >> x;
        ll ans;
        ans = (nCk(n,x, mod) * powmod(2, k-2*x, mod) % mod )* nCk(n-x,k-2*x, mod) % mod;
        cout << ans << endl;
    }
}

int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
