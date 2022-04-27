#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
//============================================================================
int v ,u;
const int num_vertices = 20;
vector<int> adj[num_vertices];
int par[9] = {-1, 0, 0, 1, 1, 2, 2, 3, 3};
//============================================================================

void dfs(int v, int parent = -1) {
    // processamento para o nó
    for(auto u: adj[v]) {
        if(u == parent) continue;
        dfs(u,v);
    }
}

void show() {
    // inserindo nós com a representação do array de pais
    adj[par[v]].push_back(v);
}

//max dist from root to every root


int main()
{
     // têm questoes que são de árvores que só falam em um grafo de v-1 arestas 
   
    return 0;
}
