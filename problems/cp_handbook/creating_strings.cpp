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
	string s, srtd_s;
	vector<string> permutations;
	cin >> s;
	srtd_s = s;
	sort(srtd_s.begin(), srtd_s.end());
	do
	{
		permutations.pb(srtd_s);
	}while(next_permutation(srtd_s.begin(), srtd_s.end()));
	cout << permutations.size()<<endl;
	for(string &s:permutations)
		cout << s << endl;
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