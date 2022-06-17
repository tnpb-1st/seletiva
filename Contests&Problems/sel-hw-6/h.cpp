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

const int LIM = 10e6;
int PHI[LIM];
void phiSieve() {
	for(int i = 1; i<= LIM; i++)PHI[i] = i;
	for(int i = 2; i<=LIM; i++) {
		if(PHI[i] == i) {
			for(int j =i; j<=LIM;j+=i)
			PHI[j] = PHI[j]/i*(i-1); 
		}
	}
}


void solve()
{
    phiSieve();
    int t;
    cin >> t;
    while(t--) {
        int x;cin>>x;
        cout << PHI[x]<<endl;
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
