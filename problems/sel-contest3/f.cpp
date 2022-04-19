#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
using namespace std;
typedef long long ll;
// typedef __int128_t bgl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main
double get_val(double &p, double &q, double &r, double &s, double &t, double &u, double &x)
{
    auto express = (p*exp(-x) + q*sin(x) + r * cos(x) + s*tan(x) + t* x * x + u);
    return express;
}
double try_me(double &p, double &q, double &r, double &s, double &t, double &u)
{
    double l = 0.0, h = 1.0, mid;
    while(h - l >= 1e-9)
    {
        double mid = (l + h)/2.0;
        if(get_val(p, q, r, s, t, u, mid) < 0)
            h = mid;
        else
            l = mid;
    }
    return l;
}


void solve()
{
	double p,q,r,s,t,u;
    while(cin >> p)
    {
        cin >> q >> r >> s >> t >> u;
        double x = try_me(p, q, r, s, t, u);
        if(abs(get_val(p,q,r,s,t,u,x)) <= 0.000100000000000000000009)
            cout << setprecision(4) << fixed << x << endl;
        else
            cout<<"No solution"<<endl;
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
