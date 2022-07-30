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

void solve()
{
  int K, N;
  cin >> K >> N;
  vvi trains(N, vi(K));
  for(int i = 0; i < K; i++)
  {
    for(int j = 1; j <= N; j++) {
      int _cow; cin >> _cow;
      trains[_cow-1][i] = j;
    }
  }

  int consistentCows = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0 ; j < N; j++){
      bool flag = true;
      for(int t = 0; t < K; t++) {
        if(trains[i][t] >= trains[j][t]){ 
          flag = false;
          break;
        }
      }
      if (flag) consistentCows++;
    }
  }

  cout << consistentCows;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    // freopen("gymnastics.in", "r", stdin);
    // freopen("gymnastics.out", "w", stdout);
    solve();
    return 0;
}