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
    // typedef __int128_t bgl;
    // range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
    // range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
    // g++ -std=c++14 -O2 -Wall test.cpp -o main
    const int inf = 1e9;
    const ll infl = 1e18;
    bool isReasonable = true;
    bool vis[150001] = {};
    ll dist[150001];
    int ne=0, nv=0;

    void dfs(int r, int &V, vector<vi> &adj) {
        vis[r] = true;
        nv++;
        ne += adj[r].size();
        for(int v: adj[r]) {
            if(!vis[v]) {
                dfs(v, V, adj);
            }
        }
    }


    void solve()
    {
        int V, E, u, v;
        cin >> V >> E;
        vvi adj(V+1);
        for(int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for(int i = 1; i <= V; i++) {
            if(!vis[i]) {
                nv = ne = 0;
                dfs(i, V, adj);
                if(ne/2 != (ll)nv*(nv-1)/2) {isReasonable = false;break;}
            }
        }
        if(isReasonable)cout<<"YES";
        else cout << "NO";
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
