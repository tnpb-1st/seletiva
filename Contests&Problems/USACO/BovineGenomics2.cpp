/*
author: eiji_tnpb
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define REP(itr,idx0,x) for(int itr = idx0; itr<x; itr++)
#define REPN(itr,idx0,x) for(int itr = idx0; itr<=x; itr++)
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
const int INF = 0x3f3f3f3f;
const ll INFLL = 8e18;
const int mx = 1e6;
// N L O S NE SE SO NO
int dr[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};
//g++ -std=c++17 main.cpp -o main && time ./main
//g++ -std=c++17 -Wall main.cpp -o main && time ./main
string spotty[500], plain[500];
int S[500][50], P[500][50], A[64];

void solve()
{
    int N,M; cin >> N >> M;
    string spotty[N], plain[N];
    REP(i,0,N) {
        cin >> spotty[i];
        REP(j,0,M) {
            if(spotty[i][j] == 'A') S[i][j] = 0;
            if(spotty[i][j] == 'C') S[i][j] = 1;
            if(spotty[i][j] == 'G') S[i][j] = 2;
            if(spotty[i][j] == 'T') S[i][j] = 3; 
        }
    }
    
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    // freopen("cownomics.in", "r", stdin);
    // freopen("cownomics.out", "w", stdout);
    solve();
    return 0;
}