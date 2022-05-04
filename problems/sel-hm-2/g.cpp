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

string smallest(string s) {
    if (s.length() % 2 == 1) return s;
    string s1 = smallest(s.substr(0, s.length()/2));
    string s2 = smallest(s.substr(s.length()/2, s.length()));
    if (s1 < s2) return s1 + s2;
    else return s2 + s1;
}
/*
SOLUTION BY tnpb
*/

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    ll a1, a2, b1, b2;
    a1 = a2 = b1 = b2 = 0;
    int l, mid, r;
    l = 0, r = s1.size(), mid = s1.size() >> 1;
    for(int i = 0; i < mid; i++) {
        a1 += s1[i];
        b1 += s2[i];
    }
    for(int i = mid; i < r; i++) {
        a2 += s1[i];
        b2 += s2[i];
    }
    bool equivalent = true;
    if((a1 != b2) && (a1 != b1) && (a2 != b1) && (a2 != b2) || (r-mid) != (mid)) equivalent = false;
    if(equivalent) cout << "YES";
    else cout << "NO";
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
