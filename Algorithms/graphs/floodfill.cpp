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
typedef vector<bool> vbool;
typedef pair<int,int> pii;

void Fill(vvi &matrix,vvi &adj, set<pii> &checked,int r0, int c0,int r1, int c1, int &m, int &n) {
    if(r1 < 0 || c1 < 0 || r1 >= m || c1 >=n) return;
    int v1 = r0 * m + c0;
    int v2 = r1 * m + c1;
    pii p1 = make_pair(v1,v2), p2 = make_pair(v2,v1);
    if(checked.find(p1) != checked.end()) {
        checked.insert(p1);
        checked.insert(p2);
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }
}

void floodFill(vvi& matrix, vvi &adj,set<pii> &checked ,int r, int c, int &m, int &n) {
    if(r < 0 || c < 0 || r >= m || c >=n) return;
    Fill(matrix, adj, checked, r, c, r-1, c, m, n); // norte
    Fill(matrix, adj, checked, r, c, r, c+1, m, n); // leste
    Fill(matrix, adj, checked, r, c, r+1, c, m, n); // sul
    Fill(matrix, adj, checked, r, c, r, c-1, m, n); // oeste
}