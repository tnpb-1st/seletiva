#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
// typedef __int128_t bgl;
// range of int valu'es -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main
struct Graph
{
	int nV = 0;
	int nE = 0;
	vector<vi> G;
	Graph(int V)
	{
		nV = V;
		G.assign(V + 1, {});
	}

	void addEdge(int u, int v) {
		G[u].pb(v);
		G[v].pb(u);
	}
};

queue<int> DFS(vector<vi> &G,int v){
	vector<int> vis(G.size()+1,-1);
	queue<int> ans;
	stack<int> pilha;
	pilha.push(v);
	while(!pilha.empty()) {
		int x = pilha.top();
		if(vis[x] == -1) vis[x] = 0;
		else {
			vis[x] = 1;
			pilha.pop();
			ans.push(x);
		}
		for(int &u : G[x]) {
			if(vis[u] == -1) {
				pilha.push(u);
			}
			// else if(vis[u] == 0 && pai[u] != x) {
			// 	printf("Cycle detected\n");
			// }
		}
	}
	return ans;
}

void solve()
{
	Graph my_graph(6);
	bool A[7] = {};
	queue<int> Q;
	my_graph.addEdge(1,2);
	my_graph.addEdge(2,3);
	my_graph.addEdge(2,4);
	my_graph.addEdge(4,5);
	my_graph.addEdge(4,6);
	queue<int> visited_dfs = DFS(my_graph.G, 1);
	while(visited_dfs.size()) {
		cout<<visited_dfs.front()<<endl;
		visited_dfs.pop();
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
