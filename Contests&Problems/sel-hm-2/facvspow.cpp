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
ll MOD = LONG_LONG_MAX;

ll power(int a, int b)
{
    int res = 1;
    while(b > 0)
    {
        if (b % 2 == 0)
        {
            a = ((a % MOD) * (a % MOD)) % MOD;
            b /= 2;
        }
        else
        {
            res = ((res % MOD) * (a % MOD)) % MOD;
            b--;
        }
    }
    return (res % MOD);
}

void solve()
{
	ll FAC[21];
    FAC[0] = 1;
    for(int i = 1; i <= 20; i++)
        FAC[i] = FAC[i-1] * i;
    int t;
    cin >> t;
    while(t--)
    {
        int l = 0, r = 20, mid, x;
        cin >> x;
        int res = 20;
        while(l <= r)
        {
            mid = l + (r - l) / 2;
            if((FAC[mid] % MOD) > power(x, mid))
            {
                res = min(res, mid);
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << res << endl;
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
