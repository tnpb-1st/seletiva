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
	int t, n, m, k;
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> k;
		vector<vi> A;
		char c;
		for(int i = 0; i < n; i++)
		{
			A.pb({});
			for(int j = 0; j < m; j++)
			{
				cin >> c;
				if(c == '.')
					A[i].pb(0);
				else
					A[i].pb(1);
			}
		}

		// for(int i = 0; i < n; i++)
		// {
		// 	for(int j = 0; j < m; j++)
		// 	{
		// 		cout << A[i][j] << " ";
		// 	}
		// 	cout<<endl;
		// }cout<<endl;


		auto check = [&](int i, int j)
		{
			for(int t = 1; t <= k; t++)
			{	
				if(((((i - t) >=0) && ((j - t) >=0)) && (A[i - t][j-t] == 0)) || (A[i][j] == 0)){
					// cout << (i-t) << (j-t)<<endl;
					return false;
				}
				if ((((i + t < n) && (j + t < m)) && (A[i + t][j + t] == 0)) || (A[i][j] == 0)){
					// cout << (i+t) << (j+t)<<endl;
					return false;
				}
			}
			return true;

		};

		bool ans = false;
		for(int i = k, j = 1; j < m; j++)
		{
			bool tmp = check(i, j);
			if(tmp == true) ans = true;
		}

		if(ans == true)
			cout << "YES"<<endl;
		else
			cout<<"NO"<<endl;
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