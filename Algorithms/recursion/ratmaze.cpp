#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 4;
int maze[N][N] = {{1,0,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,1}};
bool path[N][N] = {};
int mov_y[] = {1, 0}, mov_x[] = {0, 1};
bool cheese = false;
int path_lenght = 0;

void checkPath(int row, int col) {
    path_lenght++;
    path[row][col] = true;
    if(row == N-1 && col == N-1) cheese = true;
    for(int i = 0; i < 2; i++) {
        int r = row + mov_y[i], c = col + mov_x[i];
        if(r >= 0 && r < N && c >=0 && c < N && maze[r][c] && path[r][c]==false)
            checkPath(r,c);
    }
}


void solve() {
    checkPath(0,0);
    if(cheese) {
        cout << "The cheese was found in " << path_lenght << " steps.\n";
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << path[i][j] << ' ';
            }
            cout<<endl;
        }
    }
}

int main()
{
	time_t start, end;
	time(&start);
	cin.tie(0);
	ios::sync_with_stdio(0);
    solve();
    // freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	time(&end);
	cout << endl << fixed << (double) end-start << setprecision(3)<<endl;
	return 0;
}
