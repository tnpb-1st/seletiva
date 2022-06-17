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
const int arrLim = 1e6;
int dp[100001];
// N L O S NE SE SO NO
int mov_y[] = {-1, 0, 1, 0, 1, -1, -1, 1}, mov_x[] = {0, 1, 0, -1, 1, 1, -1, -1};
vector<ll> A(35), S1, S2;
int n,lim;
ll m; 
/*
SOLUTION BY tnpb
*/
template<class T>
void printContainer(T &container) {
	for(auto &ele:container) cout << ele << ' ';
	cout<<'\n';
}

void solve(int i,ll cur_sum = 0)
{
    if(i < lim) {
        solve(i+1, (cur_sum + A[i])%m);
        solve(i+1, cur_sum % m);
    } else {
        S1.pb(cur_sum);
    }
    // S[i] = max((0LL + cur_sum + A[i]) % m, (cur_sum + 0LL) % m);
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> A[i];
    lim = n;
    if(n <= 20){
        solve(0);
        sort(all(S1));
        cout << S1.back();
    } else {
        lim >>= 1;
        solve(0);
        swap(S1, S2);
        lim = n;
        solve(n>>1);
        sort(all(S2));
        ll best_ans = 0;
        for(auto &x:S1){
            auto ele = lower_bound(S2.begin(), S2.end(),m - x - 1);
            ll local_ans = x;
            if(ele == S2.end() || *ele > m-x-1)
                local_ans = max(local_ans, local_ans + *(--ele));
            else
                local_ans += *ele;
            if(local_ans >= m)
                best_ans = max(best_ans, local_ans % m);
            else
                best_ans = max(best_ans, local_ans);
            if(best_ans == m - 1) break;
        }
        cout << best_ans<<endl;
    }

	cin.tie(0);
	ios::sync_with_stdio(0);
	return 0;
}
