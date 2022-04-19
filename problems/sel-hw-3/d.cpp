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

pii floodFill(vector<vector<char>> &matrix,int r, int c, int &m, int &n) {
    queue<char> movements;
    movements.push(matrix[r][c]);
    bool vis[m*n] = {};
    int n_uniq_mov = 0;
    int loop_mov = 0;
    pii ans;
    vis[r*n+c] = true;
    int last_r = r, last_c = c;
    int loop_r = -1, loop_c = -1;
    while(movements.size()) {
        char next_move = movements.front();
        movements.pop();
        if(next_move == 'N') last_r--;
        else if(next_move == 'E') last_c++;
        else if(next_move == 'S') last_r++;
        else last_c--;
        if(last_r < 0 || last_c < 0 || last_r >= m || last_c >= n) {
            n_uniq_mov++;
            ans = make_pair(n_uniq_mov, loop_mov);
            return ans;
        } else if(!vis[last_r * n + last_c]) {
            n_uniq_mov++;
            vis[last_r * n + last_c] = true;
        } else {
            // achamos um loop
            loop_mov++;
            if(loop_r == -1) {
                loop_r = last_r;
                loop_c = last_c;
            }
            else if(last_r == loop_r && last_c == loop_c) {
                ans = make_pair(n_uniq_mov, loop_mov - 2);
                return ans;
            }
        }
        movements.push(matrix[last_r][last_c]);
    }
    return make_pair(-1,-1);
}

void solve()
{
    int m,n,start;
    while(scanf(" %d %d %d", &m, &n, &start)) {
        if(!m && !n && !start) break;
        vector<vector<char>> M(m, vector<char>(n));
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                scanf(" %c", &(M[r][c]));
            }
        }
        pii ans = floodFill(M, 0, start-1, m, n);
        if(ans.second == 0) {
            printf("%d step(s) to exit\n", ans.first);
        } else {
            printf("%d step(s) before a loop of %d step(s)\n", ans.first-ans.second, ans.second+1);
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
