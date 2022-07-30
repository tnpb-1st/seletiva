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
// N L O S NE SE SO NO
int dr[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};
//g++ -std=c++17 main.cpp -o main && time ./main
//g++ -std=c++17 -Wall main.cpp -o main && time ./main
vector<set<string>> feats;

void solve()
{
  int AN; cin >> AN;
  int ftIdx = 0;
  feats.resize(AN);
  for(int i = 0; i < AN; i++)
  {
    string S;int K; cin >> S >> K;
    for(int j = 0; j < K; j++) {
      string F; cin >> F;
      feats[i].insert(F);
    }
  }

  int commonFeat = 0;

  for(int a1 = 0; a1 < AN; a1++) {
    for(int a2 = a1 + 1; a2 < AN; a2++) {
      int common = 0;
      for(auto itr = feats[a1].begin(); itr != feats[a1].end(); itr++)
        if(feats[a2].find(*itr) != feats[a2].end())common++;
      commonFeat = max(commonFeat, common);
    }
  }
  cout << commonFeat + 1 << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    solve();
    return 0;
}