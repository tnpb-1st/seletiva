#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

bool isPrime(int n)
{
	for (int i = 2; i*i <= n; ++i)
	{
		if(n % i == 0)
			return false;
	}

	if(n == 1) return false;
	return true;
}

int main()
{
	cout << isPrime(1) << endl;
	return 0;
}