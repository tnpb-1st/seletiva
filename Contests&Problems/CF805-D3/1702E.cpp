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
// int N;
vpii G;
vector<char> cl;
set<int> s1,s2;

void solve()
{
  int T, N; cin >> T;
  while(T--)
  {
    cin >> N;
    G.clear();
    s1.clear();
    s2.clear();
    cl.assign(N+1, 0);
    bool is_possible = true;
    for(int i = 0; i < N; i++)
    {
      int a,b;
      cin >> a >> b;
      cl[a]++;cl[b]++;
      if((cl[a] > 2) || (cl[b] > 2)) 
      {
        is_possible = false;
      }
      if((a!=b) && !s1.count(a) && !s1.count(b)) {
        s1.insert(a);s1.insert(b);
      } else if((a!=b) && !s2.count(a) && !s2.count(b)) {
        s2.insert(a);s2.insert(b);
      } else{
        is_possible = false;
      }
    }
    if(is_possible)
      cout << "YES"<<endl;
    else
      cout << "NO"<<endl;
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
