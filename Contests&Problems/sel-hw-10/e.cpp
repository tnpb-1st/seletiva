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
/*
SOLUTION BY tnpb
*/
template<class T>
void printContainer(T &container) {
	for(auto &ele:container) cout << ele << ' ';
	cout<<'\n';
}

struct PT {
    ll x,y;

    PT(ll x = 0, ll y = 0) : x(x), y(y){}
    PT operator-(const PT &p) const {return PT(x - p.x, y - p.y);}
    ll operator%(const PT &p) const {return x * p.y - y * p.x; } // produto vetorial
    bool operator==(const PT &p) const {return x == p.x && y==p.y;}
};

void solve()
{
    int n;cin>>n;
    bool is_possible = true;
    PT nullPT(-56565,-56565);
    vector<PT> pt(4);
    vector<PT> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    if(n > 3) {
        //tentativa 1: A e B formam uma reta e C e os outros pontos formam outra reta
        // esqueci o caso de uma reta conter A, B e C
        pt[0] = points[0];
        pt[1] = points[1];
        pt[2] = points[2];
        pt[3] = nullPT;
        for(int i = 3; i < n; i++) {
            PT point = points[i];
            if((point-pt[0]) % (point-pt[1]) == 0) continue;
            else {
                if(pt[3] == nullPT) {
                    pt[3] = point;
                } else {
                    if((point-pt[2]) % (point-pt[3]) != 0) {
                        is_possible = false;
                        break;
                    }
                }
            }
        }

        // tentativa 2: B e C formam uma reta, e A formará uma reta com os não pertencentes a essa
        if(!is_possible) {
            is_possible = true;
            pt[0] = points[1];
            pt[1] = points[2];
            pt[2] = points[0];
            pt[3] = nullPT;
            for(int i = 3; i < n; i++) {
                PT point = points[i];
                if((point-pt[0]) % (point-pt[1]) == 0) continue;
                else {
                    if(pt[3] == nullPT) {
                        pt[3] = point;
                    } else {
                        if((point-pt[2]) % (point-pt[3]) != 0) {
                            is_possible = false;
                            break;
                        }
                    }
                }
            }
        }
        

        // tentativa 3: A e C formam uma reta, e B formará uma reta com os outros pontos não pertencentes a AC
         if(!is_possible) {
            is_possible = true;
            pt[0] = points[0];
            pt[1] = points[2];
            pt[2] = points[1];
            pt[3] = nullPT;
            for(int i = 3; i < n; i++) {
                PT point = points[i];
                if((point-pt[0]) % (point-pt[1]) == 0) continue;
                else {
                    if(pt[3] == nullPT) {
                        pt[3] = point;
                    } else {
                        if((point-pt[2]) % (point-pt[3]) != 0) {
                            is_possible = false;
                            break;
                        }
                    }
                }
            }
        }

        // tentativa 4: A B e C formam uma mesma reta e outros pontos formarão outra reta
        if(!is_possible) {
            is_possible = true;
            pt[0] = points[0];
            pt[1] = points[2];
            pt[2] = nullPT;
            pt[3] = nullPT;
            if((pt[1] - points[1])%(pt[0]-points[1]) != 0)is_possible = false;
            for(int i = 3; i < n && is_possible; i++) {
                PT point = points[i];
                if((point-pt[0]) % (point-pt[1]) == 0) continue;
                else {
                    if(pt[2] == nullPT) {
                        pt[2] = point;
                    }else if(pt[3] == nullPT) {
                        pt[3] = point;
                    }
                    else {
                        if((point-pt[2]) % (point-pt[3]) != 0) {
                            is_possible = false;
                            break;
                        }
                    }
                }
            }
        }
    }
    
    if(is_possible) cout << "YES";
    else cout << "NO";
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
