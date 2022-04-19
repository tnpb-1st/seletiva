#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> primeFactorise(int n)
{
	vector<ll> pfac;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
			pfac.push_back(i);
		while(n % i == 0)
		{
			n /= i;
		}
	}
	if(n > 1) pfac.push_back(n);
	return pfac;
}

int main()
{
	int x = (int) 2e32 - 1;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	auto res = primeFactorise(x);
	for(auto &x : res)
		cout << x << " ";
	return 0;
}