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
int dp[100001];
/*
SOLUTION BY tnpb
*/
template<class T>
void printContainer(T &container) {
	for(auto &ele:container) cout << ele << ' ';
	cout<<'\n';
}

vector<int> getBorder(string &str) {
    int n = str.size();
    vector<int> border(n, -1);
    for(int i = 1, j = -1; i < n; i++) {
        while( j >= 0 && str[i] != str[j+i]) {
            j = border[j];
        }
        if(str[i] == str[j+1]) {
            j++;
        }
        border[i] = j;
    }
    return border;
}

int matchPattern(const string &txt, const string &pat, const vector<int> &border) {
    int freq = 0;
    for(int i =0, j=-1; i < txt.size(); i++) {
        while(j>=0 && txt[i] != pat[j+1]) {
            j = border[j];
        }
        if(pat[j+1] == txt[i]) {
            j++;
        }
        if(j + 1 == (int)pat.size()) {
            freq++;
            j = border[j];
        }
    }
    return freq;
}

void solve()
{
    string s;
    cin >> s;
    ll ans = 0;
    ll o_ocr = 0;
    ll vv_ocr = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'o') o_ocr += vv_ocr;
        else if(i>=1 && s[i-1] == 'v') {vv_ocr++; ans+=o_ocr;}
    }
    cout<<ans;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
