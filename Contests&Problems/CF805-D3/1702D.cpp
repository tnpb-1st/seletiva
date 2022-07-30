/*
author: eiji_tnpb
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define REP(idx,x) for(int i = idx; i<x; i++)
#define REPN(idx,x) for(int i = idx; i<=x; i++)
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
const int INF = 0x3f3f3f3f;
const ll INFLL = 8e18;
const int mx = 1e6;
int dp[100001];
char M[100][100];
int R, C;
// N L O S NE SE SO NO
int dr[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};

void solve()
{
  map<char,int> mp;
  map<int,char> decode;
  int _j = 1;
  for(char c = 'a'; c <= 'z'; c++,_j++) 
  {
    mp[c] = _j;
    decode[_j] = c;
  }

  int T; cin >> T;
  while(T--)
  {
    string s; cin >> s;
    multiset<int> mset;
    ll ssum = 0,p,dif;
    for(auto &c: s)
    {
      int val = mp[c];
      ssum += val;
      mset.insert(val);
    }
    cin >> p;
    dif = ssum - p;
    string ans = "";
    while(mset.size() && (dif > 0)) 
    {
      int best_choice;
      if(!mset.size() || (dif<=0))break;
      auto ptr = mset.lower_bound(dif);
      if(ptr == mset.end()) ptr = --mset.end();
      mset.erase(ptr);
      best_choice = *ptr;
      dif -= best_choice;
    }
    for(auto &c : s) {
        if(!mset.size()) break;
        auto itr = mset.find(mp[c]);
        if(itr != mset.end()) {
            ans += decode[*itr];
            mset.erase(itr);
        }
    }
    cout << ans << endl; 
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
