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
int dp[400][400];

int TC, maxMoney, numItens;
vvi items;

int knapsackDp(int itemAtual, int currMoney)
{
  if(itemAtual == numItens) return 0;
  if(dp[itemAtual][currMoney] != -1) return dp[itemAtual][currMoney];
  int melhorOpcao = -1;
  for(int i = 0; i < items[itemAtual].size(); i++)
  {
    if(currMoney >= items[itemAtual][i]) {
        int remMoney = currMoney - items[itemAtual][i];
        int solucaoComItem = knapsackDp(itemAtual + 1, remMoney) + items[itemAtual][i];
        melhorOpcao = max(melhorOpcao,solucaoComItem);
    }
  }
  if(melhorOpcao == -1) return -1 * INF;
  return dp[itemAtual][currMoney] = melhorOpcao;
}

void solve()
{
  cin >> TC;
  while(TC--)
  {
    items.clear();
    memset(dp, -1, sizeof(dp));
    cin >> maxMoney >> numItens;
    items.resize(numItens);
    for(int i = 0; i < numItens; i++) {
        int K; cin >> K;
        for(int j = 0; j < K; j++) {
            int pi; cin >> pi;
            items[i].pb(pi);
        }
    }
    int ans = knapsackDp(0, maxMoney);
    if (ans < 0)
        cout << "no solution";
    else
        cout << ans;
    cout << endl;
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

