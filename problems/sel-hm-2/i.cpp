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
vi A(1001);
vi C;
int n,m;
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

bool checkAns(int &val) {
    C.assign(m, 0);
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(A[i] > val) return false;
        if(A[i] + C[j] <= val) {
            C[j] += A[i];
            i++;
            if(C[j] == val) j++;
        }
        else {
            j++;
        }
    }
    if(i < n && j >= m) return false;
    return true;
}

void solve()
{
    while(cin >> n) {
        cin >> m;
        for(int i = 0; i < n; i++) cin >> A[i];
        int ans;
        int l = 1, r = 1e9, mid;
        while(l <= r) {
            mid = l + (r-l)/2;
            if(mid == 6 || mid == 5)
                int a = 2;
            if(checkAns(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout<<ans<<endl;
    }

}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
