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
	int n, t, temp;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vi A(n);
		ll my_sum = 0;
		for(int i =0; i < n; i++)
		{
			cin >> temp;
			if(temp == -1)
			{
			    if(i != 0)
				    A[i] = floor((ll)my_sum / i);
				else
				    A[i] = 0;
			}
			else
			{
				A[i] = temp;
			}
			my_sum += A[i];
		}
		for(auto &x: A)
			cout << x << ' ';
		cout << endl;
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