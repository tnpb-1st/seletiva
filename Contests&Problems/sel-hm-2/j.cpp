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
vector<int> A(100001);
// N L O S NE SE SO NO
int mov_y[] = {-1, 0, 1, 0, 1, -1, -1, 1}, mov_x[] = {0, 1, 0, -1, 1, 1, -1, -1}; 
/*
SOLUTION BY tnpb
*/
template<class T>
void printContainer(T &container) {
	for(auto &ele:container) cout << ele << ' ';
	cout<<'\n';
}

void solve()
{
    int t; cin >> t;
    for(int test = 1; test <= t; test++) {
        int n, x; cin >> n;
        vector<int> V;
        int min_k = 0;
        for(int i = 0; i < n; i++) {
            cin >> x;
            V.pb(x);
            if(i == 0) A[0] = V[0];
            else A[i] = V[i] - V[i-1];
            min_k = max(min_k, A[i]);
        }
        int cur_k = min_k, increm = 0;
        for(int i = 0; i < n; i++)
        {
            if(cur_k == A[i]) cur_k--;
            else if(cur_k < A[i]) {
                increm++;
                break;
            }
        }
        if(increm) min_k++;
        cout <<"Case "<<test<<": "<<min_k<<endl;
    }
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
