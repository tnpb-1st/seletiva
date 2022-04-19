#include <bits/stdc++.h>
using namespace std;

vector<long long> factorise(long long n)
{
	vector<long long> fac;
	for(int i =1; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			fac.push_back(i);
			if(n/i != i)
				fac.push_back(n/i);
		}
	}
	// sort(fac.begin(), fac.end());
	return fac;
}

int main()
{
	auto res = factorise(24);
	for(auto &x : res)
		cout<< x << " "; 
	return 0;
}