#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
// typedef __int128_t bgl;
typedef vector<int> vi;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main



void solve()
{
	int n;
	cin >> n;
	ll n_houses, total_moves, invalid_moves;
	for(int k = 1; k <= n; k++)
	{
		n_houses = k * k;
		total_moves = (n_houses * (n_houses-1))/2LL;
		invalid_moves = 4LL * (k-1) * (k-2);
		cout << total_moves - invalid_moves << endl;
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