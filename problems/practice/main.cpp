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
    const ll infl = LONG_LONG_MAX;
    const int arrLim = 1e6;
    ll fac_dp[100001] = {};
    /*
    SOLUTION BY tnpb
    */
    int l,r, mid, n;
    ll arr[100001];


    bool bs(int x) {
        l = 1, r = n;
        while( l <= r) {
            mid = l + (r-l)/2;
            if(arr[mid] == x) return true;
            else if(arr[mid] > x) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }

    int closestLeft(ll x) {
        l = 1, r = n;
        int ans = 0;
        while(l <= r) {
            mid = l + (r-l)/2;
            if(arr[mid] <= x) {
                ans = mid;
                l = mid + 1;     
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }

    int closestRight(ll x) {
        l = 1, r = n;
        int ans = n+1;
        while(l <= r) {
            mid = l + (r-l)/2;
            if(arr[mid] < x) {
                l = mid + 1;     
            }
            else {
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }

    void solve()
    {
        int k;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> arr[i];
        sort(arr+1, arr + n + 1);
        cin >> k;
        for(int i = 0; i < k; i++) {
            int left, right; cin >> left >> right;
            int i_l = closestRight(left);
            int i_r = closestLeft(right);
            if(i_l == 0) cout << i_r << ' ';
            else cout << (i_r - i_l + 1) << ' ';
        }
    }

    int main()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
        solve();
        return 0;
    }
