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
bitset<26> present;
void bfsTopSrt(vvi &adj,vi &dependencia, vi &ans) {
    pq<int, vi, greater<int>> elem;
    for(int i = 0; i < adj.size(); i++) {
        if(dependencia[i] == 0 && present[i]) {
            elem.push(i);
        }
    }
    while(!elem.empty()) {
        int v = elem.top();
        elem.pop();
        ans.pb(v);
        for(auto &u:adj[v]) {
            if(--dependencia[u] == 0) {
                elem.push(u);
            }
        }
	}
} 
void solve()
{
	string line;
	vector<string> my_v;
	const char zero = 'A';

	while(cin >> line) {
		if(line != "#") {
			my_v.pb(line);
		} else {
			vi dependencies(26, 0), ans;
			vvi adj(26);
			if(my_v.size()> 1) {

				for(int i = 1; i < my_v.size(); i++) {
					string s1 = my_v[i-1], s2 = my_v[i];
					int lim = min(s1.size(), s2.size());
					for(int j = 0; j < lim; j++) {
						int u = s1[j] - zero, v = s2[j] - zero;
						if(s1[j] != s2[j]) {
							adj[u].pb(v);
							dependencies[v]++;
							if(!present[u])present[u] = 1;
							if(!present[v])present[v] = 1;
							break;
						}
					}
				}
			}else if(my_v.size() == 1) {
				string lonesrt = my_v[0];
				if(lonesrt.size() == 1) {
					ans.pb(lonesrt[0]-zero);
				} else {
					for(int i = 1; i < lonesrt.size(); i++) {
						int u = lonesrt[i-1] - zero, v = lonesrt[i] - zero;
						if(u != v && !present[v]) {
							adj[u].pb(v);
							dependencies[v]++;
						}
						if(!present[u])present[u] = 1;
						if(!present[v])present[v] = 1;
					}
				}
			}
			bfsTopSrt(adj, dependencies, ans);
			if(my_v.size() > 1 && my_v[0][0] == my_v[1][0] && ans.empty()) {
				ans.pb(my_v[0][0]-zero);
				present[my_v[0][0]-zero] = true;
			}
			for(int &x:ans) {
				char c = (char)x + zero;
				cout<<c;
			}
			cout<<endl;
			my_v.clear();
			present.reset();
		}
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
