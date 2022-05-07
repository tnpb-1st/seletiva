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
// int A[100][100], B[100][100], C[100][100] = {};
vvi A,B,C;
int m,n;
/*
SOLUTION BY tnpb
*/
template<class T>
void printContainer(T &container) {
	for(auto &ele:container) cout << ele << ' ';
	cout<<'\n';
}

int mov_x[] = {-1,0,1,0};
int mov_y[] = {0,1,0,-1};

void process(int r, int c) {
    if(B[r][c] == 0) {
        for(int col = 0; col < n; col++) {
            A[r][col] = 0;
        }
        for(int row = 0; row < m; row++) {
            A[row][c] = 0;
        }
    }
}

void fill(int r, int c) {
    if(A[r][c] == 1) {
        for(int col = 0; col < n; col++) {
            C[r][col] = 1;
        }
        for(int row = 0; row < m; row++) {
            C[row][c] = 1;
        }
    }
}

void solve()
{
    bool is_possible = true;
    cin >> m >> n;
    A.assign(m,vi(n,1)), B.assign(m,vi(n)), C.assign(m,vi(n,0));
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            process(i,j);
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j] == 1) {
                fill(i,j);
                break;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
           if(B[i][j] != C[i][j]) {
               is_possible = false;
               break;
           }
           if(!is_possible) break;
        }
    }

    if(!is_possible) cout << "NO";
    else {
        cout << "YES"<<endl;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cout << A[i][j] << ' ';
            }
            cout << endl;
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
