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
	int t, n, sereja = 0, dima = 0, player = 0;
	deque<int> md;
	cin >> t;
	while(t--)
	{
		cin >> n;
		md.push_back(n);
	}
	while(!md.empty())
	{
		if(md.front() >= md.back())
		{
			if(player == 0){
				sereja += md.front();
				player = 1;
			}
			else{
				dima += md.front();
				player = 0;
			}
			md.pop_front();
		}
		else
		{
			if(player == 0){
				sereja += md.back();
				player = 1;
			}
			else{
				dima += md.back();
				player = 0;
			}
			md.pop_back();
		}
	}
	cout << sereja << ' ' << dima << endl;
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