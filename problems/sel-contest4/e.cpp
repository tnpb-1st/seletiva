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
// typedef __int128_t bgl;
// range of int valu'es -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main
bitset<26> visited;
int bfs(int r,int V,vector<vi> &A)
{   
    visited[r] = true;
    int n_vtx = 1;
    queue<int> fila;
    fila.push(r);
    while(fila.size()) {
        int u = fila.front(); fila.pop();
        for(int v: A[u]) {
            if(visited[v] == false) {
                visited[v] = 1;
                fila.push(v);
                n_vtx++;
            }
        }
    }
    return n_vtx;
}

void solve()
{
    int t;
    string input;
    getline(cin, input);
    t = stoi(input);
    getline(cin, input);
    int k = 0;
    while(getline(cin,input)) {
        int max_L = (int)(input[0] - 'A') + 1;
        int n_e = 0, n_v = max_L, v, u;
        visited.reset();
        vvi G(n_v);
        set<pii> edges;
        while(getline(cin,input) && input != "") {
            v = input[0] - 'A';
            u = input[1] - 'A';

            pii edg = make_pair(min(u,v),max(u,v));
            if(edges.find(edg) == edges.end()) {
                edges.insert(edg);
                G[v].pb(u);
                G[u].pb(v);
                n_e++;
            }
        }
        int CC = 0;
        vi duplicate(2, 0);
        for(int vtx = 0; vtx < max_L; vtx++) {
            if(!visited[vtx]) {
                int nvc = bfs(vtx, n_v, G);
                if(nvc == 1)duplicate[0]++;
                if(nvc == 2)duplicate[1]++;
                CC++;
            }
        }

        cout << CC;
        cout << endl;
        if(k != t-1)cout<<endl;
        k++;
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
