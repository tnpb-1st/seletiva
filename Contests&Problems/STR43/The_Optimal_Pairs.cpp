#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define forn(x) for(int i = 1; i<=x; i++)
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
  int tc; cin >> tc;
  while(tc--)
  {
    ll n;cin>>n;
    int ans = 0;
    ll fn = n; // provado no video
    for(int i = 1; i*i <= n; i++)
    {
      if(n%i == 0)
      {
        ll div1 = i, div2 = n/i;
        if(div2 == 2) ans++;
        else ans += 2;

        if(div2 != div1 && div2 != n)
        {
          if(div1 == 2) ans++;
          else ans += 2;
        }
      }
    }
    cout << ans << endl;
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
