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
const double eps = 1e-7;

template<class T>
void printContainer(T &container) {
	for(auto &ele:container) cout << ele << ' ';
	cout<<'\n';
}

struct PT {
    int x,y;

    PT(int x = 0, int y = 0) : x(x), y(y){}
    PT operator-(const PT &p) const {return PT(x - p.x, y - p.y);}
    int operator%(const PT &p) const {return x * p.y - y * p.x; } // produto vetorial
};

void solve()
{
    int n, x0,y0;
    cin>>n>>x0>>y0;
    PT gun(x0,y0);
    vector<PT>points(n);
    vector<PT>vectors(n);
    for(int i = 0; i < n; i++) {
        int xi,yi;
        cin >> xi >> yi;
        PT storm(xi,yi);
        points[i] = storm;
        vectors[i] = storm - gun;
    }
    int num_shots = n;
    vector<bool> used(n, false);
    PT base_vec;
    for(int i = 0; i < n; i++) {
        if(used[i] == true) continue;
        base_vec = vectors[i];
        for(int j = i+1; j < n; j++) {
            if(used[j] == true) continue;
            if(base_vec % vectors[j] == 0){
                num_shots--;
                used[j] = true;
            }
        }
        used[i] = true;
    }
    cout<<num_shots;
}   

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}