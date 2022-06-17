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

    ll fastExpo(ll a, ll b) {
        ll ans = 1;
        while(b) {
            if(b & 1) ans *= a;
            a *= a;
            b >>= 1;
        }
        return ans;
    }


    void solve()
    {
        int t;
        cin >> t;
        while(t--) {
            string s,t;cin>>s>>t;
            int sSz=s.size(), tA = 0;
            for(auto &c: t) 
                if(c == 'a') tA++;
            if(tA > 0 && t.size() > 1) {
                cout << -1 << endl;
            } else if(tA == 1 && t.size() == 1) {
                cout << 1 << endl;
            } else {
                cout << fastExpo(2, sSz) << endl;
            }
        }
    }

    int main()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
        solve();
        return 0;
    }
