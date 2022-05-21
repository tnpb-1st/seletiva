#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
#include <bits/stdc++.h>

using namespace std;

class dsu{
  vector <int> parent;
  vector <int> sz;

  public:
  dsu(int n){
    parent.assign(n, -1);
    sz.assign(n, 1);

    for(int i=0; i<n; i++) parent[i] = i;
  }

  ~dsu(){
    
  }

  int find(int i){
    if(parent[i] != i) return find(parent[i]);
    return parent[i];
  }

  void unite(int a, int b){
    a = find(a);
    b = find(b);

    if(sz[a] < sz[b]) swap(a,b);
    if(a != b) sz[a] += sz[b];
    parent[b] = a;
  }

};

class dsu2D{
  vector<vector<int>> sz;
  vector<vector<pii>> parent;

  public:
  dsu2D(int m, int n){
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            parent[i][j] = {i,j};
            sz[i][j] = 1;
        }
    }

  }

  pii find(int r, int c){
    pii mpii = {r,c};
    if(parent[r][c] != mpii) return find(parent[r][c].first,parent[r][c].second);
    return parent[r][c];
  }

  void unite(int r1, int c1, int r2, int c2){
    pii a, b;
    a = find(r1,c1);
    b = find(r2,c2);

    int pr1, pc1, pr2, pc2; // parents of cell 1 and cell 2
    pr1 = a.first, pc1 = a.second, pr2 = b.first, pc2 = b.second;
    if(sz[pr1][pc1] < sz[pr2][pc2]){
        swap(a,b);
        swap(pr1,pr2);
        swap(pc1,pc2);
    } 
    if(a != b) sz[pr1][pc1] += sz[pr2][pc2];
    parent[pr2][pc2] = a;
  }

};