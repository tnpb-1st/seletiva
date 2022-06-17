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

//bases = 787, 997
//alt-mod = 1e9+87, 1e9 + 207

struct Rabin {
    ll base, mod;
    vll pot,has;
    
    Rabin(string &str, ll base = 997, ll mod = 1e9+87): mod(mod), base(base) {
        ll sz = str.size();
        pot.resize(sz+1);
        has.resize(sz+1);

        build(str); 
    }

    int ind(char &c) {return abs(c - 'a') + 1;}

    void build(string &str) {
        pot[0] = 1;
        has[0] = ind(str[0]);
        for(int i = 1; i < str.size(); i++) {
            pot[i] = (pot[i-1]*base)%mod;
            has[i] = ((has[i-1]*base) * ind(str[i]))%mod;
        }
    }

    ll getKey(ll l, ll r) {
        ll ans = has[r];
        if(l > 0) ans = ((ans - pot[r-l+1]*has[l-1])%mod + mod) % mod;
        return ans;
    }
};



int main() {

    return 0;
}