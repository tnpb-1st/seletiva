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

template<class T>
void printContainer(T &cont) {
    for(auto &x:cont)cout << x << ' ';
    cout<<endl;
};
const int MAX_FIB_N = 20;
ll mem[MAX_FIB_N+1];
vvi knapsackDP;


int fib(int n) {
    if(n == 0 || n == 1) return n;
    if(mem[n] != -1) return mem[n];
    else
        return mem[n] =  fib(n-1) + fib(n-2);
}

vi prefixSum(vi &A) {
    vi pS = A;
    for(int i = 1; i < A.size(); i++) {
        pS[i] = pS[i-1] + pS[i];
    }
    return pS;
}

vvi prefixSum2D(vvi &A, int &R, int &C) {
    vvi P(R, vi(C));
    P[0][0] = A[0][0];
    for(int i = 1; i < R; i++) {
        for(int j = 1; j < C; j++) {
            P[i][j] = P[i-1][j] + P[i][j-1] - P[i-1][j-1] + A[i][j];
        }
    }
    return P;
}

vi kadaneAlgorithm(vi &A) {
    int max_sum = INT_MIN, meh = A[0];
    vi subSum(A.size());
    for(int i = 0; i < A.size(); i++) {
        meh += A[i];
        if(meh < A[i]) meh = A[i];
        if(max_sum < meh) max_sum = meh;
        subSum[i] = max_sum;
    }
    return subSum;
}

int knapsackR(vpii &items, vvi &dp, int pos, int espaco_livre) {
    if(pos == items.size()) return 0;
    if(dp[pos][espaco_livre] != -1) return dp[pos][espaco_livre];
    int melhor_opcao = -1;
    int solucao_com_item = -1;
    if(espaco_livre >= items[pos].second) {
        int novo_espaco_livre = espaco_livre - items[pos].second;
        solucao_com_item = knapsackR(items, dp, pos + 1, novo_espaco_livre) + items[pos].first;
    }
    int solucao_sem_item = knapsackR(items, dp, pos + 1, espaco_livre);
    melhor_opcao = max(solucao_com_item, solucao_sem_item);
    return dp[pos][espaco_livre] = melhor_opcao;
}

vvi knapsackItr(vpii &items, int qtd_items, int cap_mochila) {
    vvi dp(qtd_items, vi(cap_mochila, -1));
    for(int item = 1; item <= qtd_items; item++) {
        for(int espaco_livre = 0; espaco_livre <= cap_mochila; ++espaco_livre) {
            int pegar_item = -1;
            int nao_pegar_item = dp[item - 1][espaco_livre];
            if(espaco_livre >= items[item].second) {
                pegar_item = dp[item - 1][espaco_livre - items[item].second] + items[item].first;
            }
            dp[item][espaco_livre] = max(nao_pegar_item, pegar_item);
        }
    }
    return dp;
}

int editDistanceR(string &s1, string &s2, int m, int n, vvi &dp) {
    // recursive method
    if(m == 0 || n == 0) return max(m,n);
    if(dp[m][n] != -1) return dp[m][n];
    if(s1[m-1] == s2[n-1]) {
        return dp[m][n] =  editDistanceR(s1, s2, m-1, n-1, dp);
    } else {
        int insertS2S1 = editDistanceR(s1, s2, m, n-1, dp);
        int deleteS1 = editDistanceR(s1, s2, m-1, n, dp);
        int replaceS1S2 = editDistanceR(s1, s2, m-1, n-1, dp);
        return dp[m][n] = min({insertS2S1, deleteS1, replaceS1S2}) + 1;
    }
}

int editDistance(string &s1, string &s2, int m, int n) {
    // iterative method
    int dp[m+1][n+1];
    for(int i = 0; i <= m;i++)dp[i][0] = i;
    for(int i = 0; i <= m; i++) dp[0][i] = i;
    for(int i = 0; i<= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
            }
        }
    }
    return dp[m][n];
}

int lis(vi &nums) {
    // longest increasing subsequence problem
    // return the size of longest subsequence
    // can return the subsequence
    // O(n²)
    int len = nums.size(), ans = 1;
    vi dp(len, 1);
    for(int i = len-1; i >= 0; i++) {
        for(int j = i + 1; j < len; j++) {
            if(nums[i] < nums[j]) { // < ou <= dependendo do problema
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }
    return ans;
}

int lis2(vi &nums) {
    int len = nums.size();
    queue<int> seq;
    vi S;
    for(int i = 0; i < len; i++) {
        auto it = lower_bound(S.begin(), S.end(), nums[i]);
        if(it == S.end()) {
            S.pb(nums[i]);
            seq.push(nums[i]);
        } else {
            seq.push(*it);
            *it = nums[i];
        }
    }
    return S.size();
}

const int ms = 20;
int n = 2;
int v, dp[ms][1 << ms], graph[ms][ms];
int mymin(int a, int b) {return (a>b) ? b:a;}

int TSP(int pos, int visited) {
    // O(n² 2^n)
    if(visited == (1<< n)-1) return 0;
    int ans = dp[pos][visited];
    if(~ans) return ans;
    ans = inf;
    for(int i =0;i < n;i++) {
        if(!(visited & (1 << i))) {
            ans = mymin(ans, graph[pos][i] + TSP(i, visited | (1<<n)));
        }
    }
    return dp[pos][visited] = ans;
}

string longestCommonSubsequence(string &text1, string &text2) {
    // top down
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        stack<char> rev_ans;
        string ans = "";
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        int l1 = 0, l2 = 0;
        while(l1 < m && l2 < n) {
            if(text1[l1] == text2[l2]) {
                ans += text1[l1];
                l1++;l2++;
            } else {
                if(l1 < m && dp[l1][l2] == dp[l1+1][l2]) {
                    l1++;
                } else if(l2 < n && dp[l1][l2+1] == dp[l1][l2]) {
                    l2++;
                }
            }
        }
        int longestSize = dp[0][0];
        return ans;
}

string LCS(string &t1, string &t2) {
    // bottom up approach
    int m = t1.size(), n = t2.size();
    vvi dp(m+1, vi(n+1, 0));
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(t1[i]==t2[j]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int longestSize = dp[m][n];
    string ans="";
    int c1 = m, c2 = n;
    while(c1 >= 0 && c2 >= 0) {
        if(t1[c1] == t2[c2]){
            ans+=t1[c1];
            c1--;c2--;
        }
        else {
            if(c1 >= 0 && dp[c1][c2] == dp[c1-1][c2]) {
                c1--;
            }
            else if(c2 >= 0 && dp[c1][c2] == dp[c1][c2-1]) {
                c2--;
            }
        }
    }
    reverse(all(ans));
    return ans.substr(ans.size()-1);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
    int qtde_itens = 4, capacidade_mochila = 10;
    knapsackDP = vvi(qtde_itens, vi(capacidade_mochila, -1));
    memset(mem, -1, sizeof(mem));
    vi arr = {-2, -3, 4, -1, -2, 1, 5, -3}, ans;
    ans = kadaneAlgorithm(arr);
    printContainer(ans);
	return 0;
}