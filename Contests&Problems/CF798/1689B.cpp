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

void solve()
{
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> A(n);
        for(auto &x:A) cin >> x;
        vi B = A;
        sort(all(B));
        if(A.size() == 1) {
            cout << -1 << endl;
        }else {
            for(int i = 0; i < n-1; i++) {
                if(A[i] == B[i]) swap(B[i], B[i+1]);
            }
            if(A[n-1] == B[n-1]) swap(B[n-2],B[n-1]);
            for(auto &x: B)cout << x << ' ';
            cout << endl;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
    return 0;
}