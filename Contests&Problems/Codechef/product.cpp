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
ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

ll lcm (ll a, ll b)
{
    return (a/ gcd(a,b) ) * b;
}


void solve()
{
	int t;
    cin >> t;
    while(t--)
    {
        int b, c, m;
        cin >> b >> c;
        m = lcm(b,c);
        cout << m/b << endl;
    }
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	solve();
	return 0;
}
