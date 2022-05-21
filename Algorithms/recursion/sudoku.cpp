#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 9;
int board[N][N] = {};
// N L O S NE SE SO NO
int mov_y[] = {-1, 0, 1, 0, 1, -1, -1, 1}, mov_x[] = {0, 1, 0, -1, 1, 1, -1, -1}; 

bool isSafe(int row, int col, int num) 
{ 
    
    for (int d = 0; d < N; d++)  
    { 
        
        if (board[row][d] == num) { 
            return false; 
        } 
    } 

    for (int r = 0; r < N; r++)  
    { 
            
        if (board[r][col] == num)  
        { 
            return false; 
        } 
    }  
    int s = (int)sqrt(N); 
    int boxRowStart = row - row % s; 
    int boxColStart = col - col % s; 

    for (int r = boxRowStart; 
            r < boxRowStart + s; r++)  
    { 
        for (int d = boxColStart; 
                d < boxColStart + s; d++)  
        { 
            if (board[r][d] == num)  
            { 
                return false; 
            } 
        } 
    } 

    return true; 
} 

bool solve(int n) 
{ 
	    int row = -1; 
        int col = -1; 
        bool isEmpty = true; 
        for (int i = 0; i < n; i++)  
        { 
            for (int j = 0; j < n; j++)  
            { 
                if (board[i][j] == 0)  
                { 
                    row = i; 
                    col = j; 
                    isEmpty = false; 
                    break; 
                } 
            } 
            if (!isEmpty) { 
                break; 
            } 
        } 
  
        if (isEmpty)  
        { 
            return true; 
        } 
        
        for (int num = 1; num <= n; num++)  
        { 
            if (isSafe(row, col, num))  
            { 
                board[row][col] = num; 
                if (solve(n))  
                { 
                    // print(board, n); 
                    return true; 
                } 
                else 
                { 
                    board[row][col] = 0; 
                } 
            } 
        } 
        return false; 
} 

int main()
{
	time_t start, end;
	time(&start);
	cin.tie(0);
	ios::sync_with_stdio(0);
    if(solve(9)) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
    }
    // freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	time(&end);
	cout << endl << fixed << (double) end-start << setprecision(3)<<endl;
	return 0;
}
