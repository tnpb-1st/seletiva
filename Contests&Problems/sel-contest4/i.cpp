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
typedef vector<bool> vbool;
typedef pair<int,int> pii;
// typedef __int128_t bgl;
// range of int valu'es -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main

void solve()
{
    int T;
    cin >> T;
    vector<short int> pos(26);
    while(T--) {
        string s1,s2;
        cin >> s1 >> s2;
        pos.assign(26, -1);
        for(int i =0;i<s1.size();i++)pos[(int)s1[i] - 'a'] = i;
        int cost = 0;
        for(int i = 1; i<s2.size();i++) 
            cost += abs(pos[s2[i]-'a'] - pos[s2[i-1] - 'a']);
        cout<<cost<<endl;
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
