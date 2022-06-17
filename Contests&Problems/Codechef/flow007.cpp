#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
using namespace std;
// typedef __int128_t bgl;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main

int sol1(int &x)
{
    int revn = 0;
    int n_len = log10(x);
    int pot = 1;
    for(int i = 0; i < n_len;i++)pot *=10;
    while(x > 0)
    {
        revn += (x % 10) * pot;
        pot /= 10;
        x /= 10;
    }
    return revn;
}

int sol2(int &x)
{
    int revn = 0;
    while(x > 0)
    {
        int u = x % 10;
        revn = revn * 10 + u;
        x /= 10;
    }
    return revn;
}

void solve()
{
	int t;
    cin >> t;
    while(t--)
    {
        int revn = 0;
        int x;
        cin >> x;
        cout << sol2(x) <<endl;
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
