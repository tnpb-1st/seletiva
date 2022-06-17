#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const int MOD = 1e9 + 7;

int factorial(int n)
{
	int res = 1;
	for(int i = 1; i <= n; i++)
	{
		res = 1LL * res * i % MOD;
	}
	return res;
}

int binaryExpo(int x, int y, int m)
{
	if(y == 0){
		return 1;
	}
	else if (y % 2 == 0){
		return (binaryExpo(1LL * x*x % m, y/2, m) % m);
	}else
	{
		return ((x * 1LL * binaryExpo(1LL * x*x % m, (y-1)/2, m)) % m);
	}
}

int modInv(int a, int m)
{
	return binaryExpo(a, m-2,m);
}
	
int main()
{
	
	cout << factorial(15) << endl;
	int n = 16, m = MOD;
	cout << 3 * modInv(3, m) % m << endl;
	cout << 1LL * n * modInv(n, m) % m << endl;
	return 0;
}