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
const int arrLim = 1e6;
int dp[100001];
// N L O S NE SE SO NO
int mov_y[] = {-1, 0, 1, 0, 1, -1, -1, 1}, mov_x[] = {0, 1, 0, -1, 1, 1, -1, -1};
int chess_y[] = {-1,1,-2,2,-2,2,-1,1}, chess_x[] = {-2,-2,-1,-1,1,1,2,2};
int N;

vector<vector<bool>> board(10, vector<bool>(10, 0)), visited(10, vector<bool>(10, 0));
int n_cells = 0;
int best_ans = inf;
/*
SOLUTION BY tnpb
*/
template<class T>
void printContainer(T &container) {
	for(auto &ele:container) cout << ele << ' ';
	cout<<'\n';
}

void fillBoard(int r, int i0, int len) {
    for(int i = i0; i < i0 + len; i++){
        board[r][i] = 1;
        n_cells++;
    }
}

bool check(int row, int col, int cur_ans = n_cells){
    visited[row][col] = 1;
    cur_ans--;
    for(int i = 0; i < 8; i++) {
        int r = row + chess_y[i], c = col + chess_x[i];
        if(r >= 0 && r < 10 && c >= 0 && c < 10 && !visited[r][c] && board[r][c])
            check(r,c, cur_ans);
    }
    visited[row][col] = 0;
    best_ans = min(best_ans, cur_ans);
    return true;
}

void solve()
{
    int cas = 1;
    int R;
    while(cin >> R && R) {
        n_cells = 0, best_ans = inf;
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
                board[i][j] = 0, visited[i][j] = 0;
    
        for(int i = 0; i < R; i++) {
            int x, len; cin >> x >> len;
            fillBoard(i, x, len);
        }
        check(0,0);
        cout << "Case "<< cas <<", " << best_ans;
        (best_ans != 1) ? cout <<  " squares" :  cout << " square"; 
        cout<< " can not be reached.\n";
        cas++;
    }
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
