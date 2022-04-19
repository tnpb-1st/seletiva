#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
// typedef __int128_t bgl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall -o main

void solve()
{
	int t;
    cin >> t;
    while(t--)
    {
        int n;
        ll x;
        cin >> n;
        cin.ignore();
        string in;
        vector<ll> my_v;
        getline(cin, in);
        stringstream S(in);
        while(S >> x)
        {
            my_v.pb(x);
        }
        int n_coins = 1;
        vector<ll> dp(n + 1);
        dp[1] = my_v[0];
        for(int i = 1; i < n - 1; i++)
        {
            if(dp[n_coins] + my_v[i] < my_v[i + 1])
            {
                dp[n_coins + 1] = dp[n_coins] + my_v[i];
                n_coins++;
            }
        }
        n_coins++;
        cout << n_coins<<endl;
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