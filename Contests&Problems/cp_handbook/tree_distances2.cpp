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
const int limSize = 1e6;
const int inf = 1e9;
const ll infl = 1e18;

vi tree[200001];
ll res[200001];
int subSize[200001];
ll subDist[200001];
int n;

void dfs1(int node, int parent) {
    subSize[node] = 1;

    for(int &child: tree[node]) {
        if (child != parent) {
            dfs1(child, node);
            subSize[node] += subSize[child];
            subDist[node] += subSize[child] + subDist[child];
        }
    }
}

// calculate sum of distances for each node
void dfs(int node, int parent) {
    res[node] = res[parent] + n - 2*subSize[node];

    for(int &child: tree[node]) {
        if(child != parent)
            dfs(child, node);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int a, b, sz;
    cin >> sz;
    n = sz;
    for(int i = 1 ; i < sz; i++) {
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    dfs1(1,-1);
    res[1] = subDist[1];

    for(int &child:tree[1])
        dfs(child, 1);
    
    for(int i = 1; i <= sz; i++) {
        cout<<res[i] << ' ';
    }
    return 0;
}