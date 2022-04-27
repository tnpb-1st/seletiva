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
int dp[100001];

// problem for given an graph of a tree, find the number of distinct elements
// existe for every subtree of each node
vi tree[200001];
int c[200001]; // cores dos nós
int res[200001]; // número de cores distintas para cada nó
set<int> *st[200001];

void dfs(int node, int parent) {
   int mx = 0;
   int mx_node = -1;

   for(int child:tree[node]) {
       if(child != parent) {
            dfs(child, node);
            if(st[child]->size() > mx) {
                mx = st[child]->size();
                mx_node = child;
            }
       }
    }
    if(mx_node == -1) st[node] = new set<int>();
    else st[node] = st[mx_node];

    st[node]->insert(c[node]);

    for(int child: tree[node]) {
        if(child != parent && child != mx_node) {
            for(int color: *st[child]) {
                st[node]->insert(color);
            }
        }
    }
    res[node] = st[node]->size();
} 

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,a,b;
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> c[i];
    for(int i = 1; i<= n-1; i++) {
        cin >> a >> b;
        tree[a].pb(b);tree[b].pb(a);
    }
    dfs(1, -1);
    
    for(int i = 1; i <= n; i++) cout << res[i] << ' ';
}