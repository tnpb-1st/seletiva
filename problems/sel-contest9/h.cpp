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
/*
SOLUTION BY tnpb
n = 0, (1+1+1+1) mod 5 = 4
n = 1, (1+2+3+4) mod 5 = 0
n = 2, (1+4+4+1) mod 5 = 0
n = 3, (1+3+2+4) mod 5 = 0
n = 4, (1+1+1+1) mod 5 = 4
n = 5, (1+2+3+4) mod 5 = 0
n = 6, (1+4+4+1) mod 5 = 0
n = 7, (1+3+2+4) mod 5 = 0
n = 8, (1+1+1+1) mod 5 = 4
:= n%4 = 4, else 0
*/

void solve()
{
    string s;
    cin>>s;
    int x;
    if(s.size() < 4) x = stoi(s);
    else x = stoi(s.substr(s.size()-2));
    if(x%4==0)cout<<4;
    else cout << 0;
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
