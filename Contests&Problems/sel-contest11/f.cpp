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

int prio(char c) {
    if(c == '+') return 1;
    else if(c == '-') return 2;
    else if(c == '*') return 3;
    else if(c == '/') return 4;
    else return 5;
}

void process(string &s) {
    queue<char> output;
    stack<char> operat;
    for(char &c:s) {
        if(c >= 'a' && c <= 'z') output.push(c);
        else if(c != '(' && c != ')') {
            while(operat.size() && ( (operat.top()!='(') && ( (prio(operat.top()) > prio(c)) ) || ((prio(operat.top()) ==
            prio(c)) && (c != '^')) ) ) {
                output.push(operat.top());
                operat.pop();
            }
            operat.push(c);
        }
        else if(c == '(') operat.push(c);
        else {
            while(operat.size() && operat.top()!= '(') {
                output.push(operat.top());
                operat.pop();
            }
            if(operat.size() && operat.top() == '(')operat.pop();
        }
    }
    while(operat.size()) {
        output.push(operat.top());
        operat.pop();
    }
    while(output.size()) {
        cout<<output.front();
        output.pop();
    }
    cout<<endl;
}

void solve()
{
    int t;cin>>t;
    while(t--) {
        string s;cin>>s;
        process(s);
    }
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
