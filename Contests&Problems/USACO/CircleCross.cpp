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
    string s; cin >> s;
    pii joker = {-1,-1};
    vector<pii> A(26, joker);
    for(int i = 0; i < s.size(); i++)
    {
      char c = s[i];
      int idx = c - 'A';
      if(A[idx] == joker) {
        A[idx].first = i;
      } else {
        A[idx].second = i;
      }
    }

    int ans = 0;

    for(char c1 = 'A'; c1 <= 'Z'; c1++) {
      int idx = c1 - 'A';
      int st1 = A[idx].first, end1 = A[idx].second;
      for(int i = end1+1; i < s.size(); i++) {
        int idx2 = s[i] - 'A';
        if(A[idx2].first > st1 && end1 > A[idx2].first && 
        A[idx2].second > end1) ans++;
      }
    }
    cout << ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    solve();
    return 0;
}