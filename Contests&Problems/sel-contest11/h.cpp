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
    int n;cin>>n;
    ll A[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    sort(A, A + n);
    bool is_possible = false;
    for(int i = 1; i < n-1; i++) {
        if(A[i-1] + A[i] > A[i+1]) {
            is_possible = true;
            break;
        }
    }
    if(is_possible)cout<<"YES";
    else cout << "NO";
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
