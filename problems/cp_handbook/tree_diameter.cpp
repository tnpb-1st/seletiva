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

// problem for given an graph of a tree, find the subtree size of each node
vi tree[200001];
int f[200001]; // maior caminho que começa em um no v e termina em sua sub-arvore(altura)
int g[200001]; // maior caminho que começa em um no x de sua subarvore, passar por v e termina num outro no y no de sua sub-arvore
int d;

void dfs(int node, int parent = -1) {
    vi childList;

    for(int &child: tree[node]) {
        if(child != parent) {
            dfs(child, node);
            f[node] = max(f[node], f[child] + 1);
            childList.pb(f[child]);
        }
    }

    d = max(d, f[node]);
    if(childList.size() >= 2) {
        sort(all(childList));
        g[node] = 2 + childList[childList.size()-1] + childList[childList.size()-2];
        d = max(d, g[node]);
    }
} 

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,a,b;
    cin >> n;
    for(int i = 1; i<= n-1; i++) {
        cin >> a >> b;
        tree[a].pb(b);tree[b].pb(a);
    }
    dfs(1, -1);
    cout<<d;
}