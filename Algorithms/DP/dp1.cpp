#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int MX = 1e6 + 1, MTXMAX = 1001;
long long dp[MX+1];
long long psum[MX+1];
long long dp2[MTXMAX][MTXMAX];
long long M[MTXMAX][MTXMAX];
//g++ -std=c++17 main.cpp -o main && time ./main
//g++ -std=c++17 -Wall main.cpp -o main && time ./main

//isolated functions
long long fact(long long x)
{
  if(x == 1) return dp[1] = 1;
  else if(dp[x] == 0) return dp[x] = x * fact(x-1);
  else return dp[x];
}

long long fib(long long x) {
  if(x == 0) return 0;
  else if(x == 1 ) return 1;
  else if(dp[x] != 0) return dp[x];
  else return dp[x] = fib(x-1) + fib(x-2);
}

// Prefix Sum Functions

long long rangeSum(int L, int R)
{
  if(L == 0) return R;
  else return(psum[R] - psum[L-1]);
}

void buldPsum(vector<int> &A)
{
  psum[0] = A[0];
  for(int i = 1; i < (int)A.size(); i++)
    psum[i] = A[i] + psum[i-1];
}

// Matrix prefix sum Functions

void mtxPsum(int n, int m)
{
  dp2[0][0] = M[0][0];
  for(int i = 1; i < n; i++) dp2[i][0] = dp2[i-1][0] + M[i][0];
  for(int j = 1; j < m; j++) dp2[0][j] = dp2[0][j-1] + M[0][j];
  for(int i = 1; i < n; i++) {
    for(int j = 1; j < n; j++) {
      dp2[i][j] = dp2[i][j-1] + dp2[i-1][j] - dp2[i-1][j-1] + M[i][j];
    }
  } 
}

long long submatrixSum(int i1, int j1, int i2, int j2)
/* 
 qualquer submatriz é definida por dois índices, o limite superior esquerdo
 e olimite inferior direito
*/
{
  long long res = dp2[i2][j2];
  if(i1 >= 1) res -= dp2[i1-1][j2];
  if(j1 >= 1) res -= dp2[i2][j1-1];
  if(i1 >= 1 && j1 >= 1) res += dp2[i1-1][j1-1];
  return res;
}

// resolver o problema de subarray com soma maxima
void buildSubArrSumDP(vector<long long> &A, vector<long long> &dp,
  vector<long long> &pref, vector <long long> &mn)
{
  // criamos o prefix sum array
  // criamos o array com prefix sum minimos para dado indice
  // e por fim o array que armazenará as dps
  int n = (int) A.size();
  dp.resize(n+1, 0);
  pref.resize(n+1, 0);
  mn.resize(n+1,0);
  dp[0] = -1e18;

  for(int i = 0; i < n; i++) {
    pref[i+1] = pref[i] + A[i+1];
    mn[i+1] = min(mn[i], pref[i+1]);
    dp[i+1] = max(dp[i], pref[i+1] - mn[i]);
  }
}

long long subArrayMaxSum(int i)
{
  //if not built
  vector<long long> dp,pref,mn;
  buildSubArrSumDP(A,dp,pref,mn);
  // i >= 1
  return dp[i];
}

long long maxSubArraySum(vector<long long> &A, int lim)
{
  long long maxSoFar = A[0];
  long long curMax = A[0];

  for(int i = 1; i < size; i++) {
    currMax = max(A[i], curr_max + A[i]);
    maxSoFar = max(maxSoFar,currMax);
  }
  return maxSoFar;
}

int knapsackBrute (int itemAtual, int espacoLivre)
// problema da mochila se resolvido com brute force, complexidade exponencial
{
  if(itemAtual == numItens) return 0;
  int melhorOpcao = -1;
  int solucaoComItem = -1;
  if(espacoLivre >= peso[itemAtual]) {
    int novoEspacoLivre = espacoLivre - peso[itemAtual];
    solucaoComItem = knapsackBrute(itemAtual + 1, novoEspacoLivre) + preco[itemAtual];
  }
  int solucaoSemItem = knapsackBrute(itemAtual + 1, espacoLivre);
  melhorOpcao = max(solucaoComItem, solucaoSemItem);
  return melhorOpcao;
}

int knapsackDp(int itemAtual, int espacoLivre)
{
  if(itemAtual == numItens) return 0;
  if(dp[itemAtual][espacoLivre] != -1) return dp[itemAtual][espacoLivre];
  int melhorOpcao = -1;
  int solucaoComItem = -1;
  if(espacoLivre >= peso[itemAtual]) {
    int novoEspacoLivre = espacoLivre - peso[itemAtual];
    solucaoComItem = knapsackDp(itemAtual + 1, novoEspacoLivre) + preco[itemAtual];
  }
  int solucaoSemItem = knapsackDp(itemAtual + 1, espacoLivre);
  melhorOpcao = max(solucaoSemItem, solucaoComItem);
  return dp[itemAtual][espacoLivre] = melhorOpcao;
}

int knapsackDpItr(vector<int> &pesos, vector<int> &precos, int CAP_MOCHILA)
{
  const int QTD_ITENS = pesos.size();
  vector<vector<int>> dp(MTXMAX, vector<int>(MTXMAX, -1)); // incializar o vetor de DP
  for(int item = 1; item <= QTD_ITENS; ++item)
  {
    for(int espacoLivre = 0; espacoLivre <= CAP_MOCHILA; ++espacoLivre) {
      int pegarItem = -1;
      int naoPegarItem = dp[item-1][espacoLivre];
      if(espacoLivre >= pesos[item]) {
        pegarItem = dp[item -1][espacoLivre - pesos[item]] + precos[item];
      }
    }
    dp[item][espacoLivre] = max(pegarItem, naoPegarItem);
  }
}

int lis(vector<int> &A, int idx)
{
  // O(n²)
  const int SZ = A.size();
  vector<int> dp(SZ, 1);
  for(int i = 1; i < SZ; i++)
  {
    for(int j = i - 1; j >= 0; j--)
    {
      if(A[j] < A[i]) // o problema nesse caso é estritamente decrescente
        dp[i] = max(dp[i], dp[j] + 1);0
    }
  }
  return dp[idx];
}

int lisOpt(vector<int> &A, int idx)
{
  // O(n log n)
  // só funciona para LIS estritamente crescentes
  const int SZ = A.size();
  vector<int> S;
  vector<int> pred(SZ, -1);
  for(int i = 0; i < SZ; i++){
    auto it = lower_bound(S.begin(),S.end(), A[i]);
    if(it == S.end()) 
      S.push_back(A[i]);
    else{
      pred[lower_bound(A.begin(),A.end(),*it)] = -1;
      *it = A[i];
    }
    if(S[i] != S.front())
      pred[i] = lower_bound(S.begin(),S.end(),S[i-1]);
    else
      pred[i] = i;
  }
  return S.size();
  // para recuperar a resposta é necessário ter um vetor auxiliar de "precedentes" como em djikstra
  // para salvar o elemento anterior 
}

int main() {
  cout << fib(5) << endl;
}