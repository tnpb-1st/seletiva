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
	int t, y, x;
	cin >> t;
	while(t--)
	{
		cin >> x >> y;
		int biggest_cord = max(x,y);
		if(biggest_cord == 1) cout << 1 << endl;
		else
		{
			ll my_ceil = (ll)(biggest_cord) * (biggest_cord);
			ll lower = my_ceil - (2LL * biggest_cord - 1) + 1;
			ll middle = (lower + my_ceil)/2LL;
			ll diff = abs(x - y);
			if ((y == biggest_cord) && (y & 1))
				cout << middle + diff << endl;
			else if (y == biggest_cord && (!(y & 1)))
				cout << middle - diff << endl;
			else if ((x == biggest_cord) && (x & 1))
				cout << middle - diff << endl;
			else
				cout << middle + diff << endl;
		}
		
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