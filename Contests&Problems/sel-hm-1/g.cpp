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
	int t;
    ll x, y;
    vector<pair<ll,ll>> V;
    cin >> t;
    while(t--)
    {
        cin >> x >> y; 
        V.pb(make_pair(x,y));
    }
    sort(all(V));
    pair<ll,ll> l1 = make_pair(-1,-1), l2 = make_pair(-1,-1);
    pair<ll,ll> actual;
    for(auto &pr:V)
    {
        if(l1.second < pr.first)
        {
            l1 = pr;
            continue;
        }
        else if(l2.second < pr.first)
        {
            l2 = pr;
            continue;
        }
        else
        {
            cout<<"NO";return;
        }
    }
    cout<<"YES";
        
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