#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
using namespace std;
typedef long long ll;
// typedef __int128_t bgl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main

void solve()
{
	int t, x, cont = 1;
    string s;
    cin >> t;
    while(cont <= t)
    {
        int min_sp = -1;
        cin.ignore();
        getline(cin, s);
        stringstream S(s);
        while(S >> x)
        {
            if(x > min_sp) min_sp = x;     
        }
        cout <<"Case " << cont <<": " << min_sp << endl;
        cont++;
    }
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	solve();
	return 0;
}