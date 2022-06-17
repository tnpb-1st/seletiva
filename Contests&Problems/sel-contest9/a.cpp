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
/*
SOLUTION BY tnpb
*/

void solve()
{
    int T; cin>>T;
    for(int i = 1; i <= T; i++) {
        stack<int> S1,S2;
        string line;cin>>line;
        for(char &ch:line){
            if(ch == '1')S1.push(1);
            else S1.push(0);
        }
        int cont = 0;
        bool is_possible = true;
        while(!S1.empty()) {
            int x = S1.top();S1.pop();
            if(x == 0) {
                cont++;
                S2.push(0);
            } else {
                if(cont < 2) {
                    is_possible = false;
                    break;
                }
                S2.pop();S2.pop();cont-=2; 
            }
        }
        cout << "Case "<< i << ": ";
        if(S2.empty() && is_possible) {
            cout<<"yes"<<endl;
        }else {
            cout<<"no"<<endl;
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
