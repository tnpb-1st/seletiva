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
const int maxValue = 110000;
int N;
ll W, maxVal;
vll costs;
vi items;
vvll dp;

ll knapsackR(int pos, ll valor_restante) {
    if(pos == items.size()) return valor_restante == 0 ? 0 : inf;
    if(dp[pos][valor_restante] != -1) return dp[pos][valor_restante];
    ll melhor_opcao;
    ll solucao_com_item = inf;
    if(valor_restante >= items[pos]) {
        ll novo_valor_restante = valor_restante - items[pos];
        solucao_com_item = knapsackR(pos + 1, novo_valor_restante) + costs[pos];
        melhor_opcao = min(solucao_com_item, melhor_opcao);
    }
    ll solucao_sem_item = knapsackR(pos + 1, valor_restante);
    melhor_opcao = min(solucao_com_item, solucao_sem_item);
    return dp[pos][valor_restante] = melhor_opcao;
}

ll auxSolve(ll max_value) {
    for(ll val = maxVal; val >= 0; val--) {
        if(knapsackR(0, val) <= W) {
            return val;
        }
    }
    return 0;
}

void solve()
{
    cin >> N >> W;
    costs.resize(N);
    items.resize(N);
    maxVal = 0;
    dp.assign(N, vll(maxValue, -1));
    for(int i = 0; i<N;i++) {
        cin >> costs[i] >> items[i];
        maxVal += items[i];
    }
    ll ans = auxSolve(W); 
    cout << ans;
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
