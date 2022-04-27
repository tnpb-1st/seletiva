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

ll dp[1000001], inv[1000001];
//bases = 787, 997
//alt-mod = 1e9+87, 1e9 + 207

ll chr(char &c) {return c - 'a' + 1;}

struct HashStr
{
    ll p, p_power, mod;
    
    HashStr(string &str, ll base=787, ll md=1e9+87 ,ll p_pwr = 1) {
        p = base, p_power = p_pwr, mod = md;
        inv[0] = 1;
        dp[0] = chr(str[0]);

        for(int i = 1; i < str.size(); i++) {
            char ch = str[i];
            p_power = (p_power * p) % mod;
            inv[i] = power(p_power, mod - 2);
            dp[i] = (dp[i-1] + chr(ch)*p_power)%mod;
        }
    }

    ll power(ll a, ll n) {
        ll res = 1;
        while(n) {
            if(n & 1) res = (res * a) % mod;

            n>>=1;
            a = (a*a)%mod;
        }
    }

    ll subStrHash(int l, int r) {
        int res = dp[r];
        if(l > 0) res -= dp[l-1];
        res = (res*inv[l])%mod;
        return res;
    }
};



int main() {

    return 0;
}