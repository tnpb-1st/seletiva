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

int foo(vi &A, int remaining, int equal) {
    if(remaining <= 0) return 0;
    else {
        for(int i = A.size()-equal-1; i >= 0; i--) {
            if(A[i] == A[A.size()-equal]) equal++;
            else break;
        }
        if(equal >= remaining) return 0;
        equal >= 2 ? equal = log2(equal)*2 : 1;
        equal > 1 ? equal*=equal : equal = 2;
        return 1 + foo(A, remaining - equal, equal);
    }
}

void solve()
{
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n;
        vi A(n);
        set<int> ms;
        for(int i = 0; i < n; i++) {
            cin >> A[i];
            ms.emplace(A[i]);
        }
        int ans = log2(n);
        if(ms.size() == 1) ans = 0;
        else ans = min(ans, (int)ms.size()-1);
        cout <<ans<<endl;
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
