#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
// g++ main.cpp -o main && time ./main

void solve()
{
	int n = 3;
	vector<int> subset;

	for(int mask = 0; mask < (1 << n); mask++)
	{
		vector<int> subset;
		for(int j =0; j < n; j++)
		{
			if((mask >> j) & 1)
			{
				subset.push_back(j);
			}
		}
	}

	for(auto &x:subset)
		cout << x << endl;
}

int main()
{
	solve();
	return 0;
}
