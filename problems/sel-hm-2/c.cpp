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

void solve()
{
	int n;
    cin >> n;
    ll A[n], B[n];
    for(int i=0; i < n; i++)
    {
        cin >> A[i];
        if(i == 0)
        {
            B[0] = A[0];
        }
        else
        {
            B[i] = A[i] + B[i - 1];
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        int x;
        cin >> x;
        cout << 1 + (lower_bound(B, B+n, x) - B) << endl;
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
