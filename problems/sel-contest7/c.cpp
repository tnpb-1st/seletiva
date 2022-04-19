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
/*
SOLUTION BY tnpb
*/

ll gcd(ll a, ll b) {
    while(b) a%=b, swap(a,b);
    return a;
}


void solve()
{
    int tests;cin>>tests;
    while(tests--) {
        int n, k, cont, x;
        ll ans = 0;
        cin >> n >> k;
        k++;
        vi bank_notes(n);
        for(int i =0; i <n; i++) {
            cin >> bank_notes[i];
            cont = 1;
            while(bank_notes[i]--) cont *=10;
            bank_notes[i] = cont;
        }
        for(int i = 0; i<n; i++) {
            cont = k;
            if ( i + i < n) cont = min(cont, bank_notes[i+1]/bank_notes[i]-1);
            ans += (ll)bank_notes[i] * (ll)cont;
            k -=  cont;
        }
        cout << ans << endl;
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
