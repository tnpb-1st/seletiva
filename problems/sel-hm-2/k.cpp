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
vector<pii> remaining;
int M[8][8];
int fr[8][9], fc[8][9], fg[4][9];
/*
SOLUTION BY tnpb
*/
template<class T>
void printContainer(T &container) {
	for(auto &ele:container) cout << ele << ' ';
	cout<<'\n';
}

int getGroup(int &row, int &col) {return (row/4)*2 + (col/4);}

bool checkRow(int row) {
	for(int col = 0; col < 8; col++) {
		int x = M[row][col];
		if(x == 0) continue;
		fr[row][x]++;
		if(fr[row][M[row][col]] > 1) return false;
	}
	return true;
}

bool checkCol(int col) {
	for(int row = 0; row < 8; row++) {
		int x = M[row][col];
		if(x == 0) continue;
		fc[row][x]++;
		if(fc[row][x] > 1) return false;
	}
	return true;
}

bool checkGroup(int row, int col) {
	int G = getGroup(row, col);
	int i,r,j,c;
	if(G == 0) i=0,r=4,j=0,c=4;
	else if(G == 1) i=0,r=4,j=4,c=8;
	else if(G == 2) i=4,r=8,j=0,c=4;
	else i=4,r=8,j=4,c=8;
	for(;i<r;i++) {
		for(j;j<c;j++) {
			int x = M[i][j];
			if(x == 0) continue;
			fg[G][x]++;
			if(fg[G][x] > 2) return false;
		}
	}
	return true;
}

bool is_valid(int r, int c, int val) {
	if(fr[r][val] > 0) return false;
	if(fc[c][val] > 0) return false;
	int G = getGroup(r,c);
	if(fg[G][val] > 1) return false;
	if(M[r][c] != 0) return false;
	return true;
}

void insertVal(int r, int c, int val) {
	fr[r][val]++;
	fc[c][val]++;
	fg[getGroup(r,c)][val]++;
	M[r][c] = val;
}

void removeVal(int r, int c, int val) {
	fr[r][val]--;
	fr[c][val]--;
	fg[getGroup(r,c)][val]--;
	M[r][c] = 0;
}

bool backtrack(int idx = 0)
{
	if(idx == remaining.size()) return true;
	pii coords = remaining[idx];
	int r = coords.first, c = coords.second;
	for(int val = 1; val <= 8; val++) {
		if(is_valid(r,c,val)) {
			insertVal(r,c,val);
			bool good_mov = backtrack(idx + 1);
			if(good_mov) return true;
			removeVal(r,c,val);
		}
	}
	return false;
}

void solve()
{
	int T;cin>>T;
	for(int t = 1; t <= T; t++) {
		memset(fr, 0, sizeof(fr));
		memset(fg, 0, sizeof(fg));
		memset(fc, 0, sizeof(fc));
		remaining.clear();
		for(int i = 0; i < 8; i++) {
			for(int j = 0; j < 8; j++) {
				cin >> M[i][j];
				if(M[i][j] == 0)
					remaining.push_back({i,j});
			}
		}
		bool is_valid = true;
		for(int i = 0; i < 8; i++){
			is_valid = min(checkCol(i), is_valid);
			is_valid = min(checkRow(i), is_valid);
		}
		is_valid = min(is_valid, checkGroup(0,0));
		is_valid = min(is_valid, checkGroup(0,4));
		is_valid = min(is_valid, checkGroup(4,0));
		is_valid = min(is_valid, checkGroup(4,4));
		if(is_valid) is_valid = backtrack();
		if(!is_valid) {
			cout << "Test case #" << t <<  ": NO" << endl;
		} else {
			cout << "Test case #" << t <<  ": YES" << endl;
			for(int i = 0; i < 8; i++) {
				for(int j = 0; j < 8; j++) {
					cout << M[i][j];
					if(j < 7) cout << ' ';
				}
				cout<<endl;
			}
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
