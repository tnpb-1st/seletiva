#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool board[101][101];
int m, n;

void printMtx() {
    for(int i = 0; i < m; i++) {
        for(int j=0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

bool isSafe(int row, int col) {
    // check all columns for a row r
    for(int c = 0; c < col; c++)
        if(board[row][c]) return false;
    // check diagonal r = c
    for(int r = row, c = col; r >= 0 && c >= 0; r--,c--){
        if(board[r][c]) return false;
    }
    // check diagonal r = -c
    for(int r = row, c = col; r < m && c >= 0; r++, c--)
        if(board[r][c]) return false;
    
    return true;
}

bool solveRec(int col) {
    if(col == n) return true;

    for(int i = 0; i < n; i++) {
        if(isSafe(i, col)) {
            board[i][col] = 1;
            if(solveRec(col+1)) return true;
            board[i][col] = 0;
        }
    }
    return false;
}

bool solve() {
    if(solveRec(0) == false)
        return false;
    else {
        printMtx();
        return true;
    }    
}

int main()
{
	time_t start, end;
	time(&start);
	cin.tie(0);
	ios::sync_with_stdio(0);
    m = n = 4;
    solve();
    // freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	time(&end);
	cout << endl << fixed << (double) end-start << setprecision(3)<<endl;
	return 0;
}
