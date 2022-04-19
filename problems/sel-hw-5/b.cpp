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
int t, k, d, v, n;
vpii T;
vvll dp;
vbool used;
vi costs;
bool taken[35][1005], mark[35];
vector<vector<string>> inp(1);

ll brute(int item_atual, int espaco_livre) {
    if(item_atual == n) return 0;
    if(dp[item_atual][espaco_livre] != -1) return dp[item_atual][espaco_livre];
    ll melhor_opcao = -1;
    ll solucao_com_item = -1;
    if(espaco_livre >= costs[item_atual]) {
        int novo_espaco_livre = espaco_livre - costs[item_atual];
        solucao_com_item = brute(item_atual + 1, novo_espaco_livre) + T[item_atual].second;
    }
    ll solucao_sem_item = brute(item_atual + 1, espaco_livre);
    taken[item_atual][espaco_livre] = (solucao_com_item > solucao_sem_item);
    melhor_opcao = max(solucao_com_item, solucao_sem_item);
    return dp[item_atual][espaco_livre] =  melhor_opcao;
}

void solve()
{
    string line;
    int cont = 0;
    while(getline(cin,line)) {
        if(line != "")
            inp[cont].pb(line);
        else{
            cont++;
            inp.pb(vector<string>());
        }
    }
    string s;
    for(int i = 0; i < inp.size(); i++) {
        s = inp[i][0];
        stringstream S(s);
        S >> t >> k;
        s = inp[i][1];
        S = stringstream(s);
        S >> n;
        T.clear();
        dp.assign(n+1, vll(t+1, -1));
        memset(taken, false, sizeof(taken));
        costs.resize(n);
        for(int j = 2, ind=0; j < inp[i].size(); j++,ind++) {
            s = inp[i][j];
            S = stringstream(s);
            S >> d >> v;
            T.pb({d,v});    
            costs[ind] = 3 * k * d;
        }
        ll ans = brute(0, t);
        cout << ans << endl;
        int o = 0, j  = t, cont = 0;
        while(o < n) {
            if(taken[o][j]) {
                mark[o] = true;
                cont++;
                j = j - costs[o];
            }
            o++;
        }
        cout<<cont<<endl;
        for(int o = 0; o < n; o++) {
            if(mark[o]) {
                cout<< T[o].first << ' ' << T[o].second<<endl;
            }
        }
        if(i != inp.size()-1)cout<<endl;
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
