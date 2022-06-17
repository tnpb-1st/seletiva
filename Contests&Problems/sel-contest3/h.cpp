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
    vector<pair<ll, ll>> V;
    ll d, i1, i2, x;
    cin >> n >> d;
    vector<ll> TF(n);
    for(int i =0; i < n; i++)
    {
        cin >> i1 >> i2;
        V.pb({i1, i2});
    }
    sort(all(V));
    TF[0] = V[0].second;
    for(int i = 1; i < n; i++)
    {
        TF[i] = TF[i - 1] + V[i].second;
    }
    ll pt1, pt2, mid;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        pt1 = i;
        pt2 = n-1;
        int l = i - 1;
        while(pt1 <= pt2)
        {
            mid = pt1 + (pt2-pt1)/2;
            if(V[mid].first - V[i].first + 1 <= d)
            {
                if(i == 0) ans = max(ans, TF[mid]);
                else ans = max(ans, TF[mid] - TF[l]);
                pt1 = mid + 1;
            }
            else {
                pt2 = mid - 1;
            }
        }
    }
    cout << ans << endl;
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