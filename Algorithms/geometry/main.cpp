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

struct PT {
    double x,y;

    PT(double x = 0, double y = 0) : x(x), y(y){}
    PT operator+(const PT &p) const {return PT(x + p.x, y + p.y);}
    PT operator-(const PT &p) const {return PT(x - p.x, y - p.y);}
    PT operator*(double c) const {return PT(x * c, y * c);}
    PT operator/(double c) const {return PT(x/c, y/c); }
    double operator!() const {return hypot(x,y); }
    double operator*(const PT &p) const {return x * p.x + y * p.y; }
    double operator%(const PT &p) const {return x * p.y - y * p.x; } // produto vetorial
    double operator^(const PT &p) const {return atan2(*this % p, *this * p);}
};

int main() {
    return 0;
}