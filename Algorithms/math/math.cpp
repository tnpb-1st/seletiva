#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000 // 1 bi
using namespace std;
//g++ math.cpp -o a && time ./a

int r_power(int x, int y)
{
	if(y == 0)
		return 1;

	int tmp = r_power(x, y/2);
	tmp*= tmp;
	if(y % 2 == 0)
		return tmp;
	else
		return tmp * x;
}

int power(int x, int y)
{
	// 3^5 = 3^101
	int res = 1;
	int n = y;
	while(n & 1)
	{
		if(n & 1)
			res *= x; //

		n >>=1; //
		x*=x; //
	}
	return res;
}

long long power2(int x, int y)
{
	long long res = 1;

	while(y > 0)
	{
		if(y % 2 != 0)
			res *= x; //

		y/=2; // 1
		x *=x; // 5^8
	}
	return res;
}


void sieveE(ll n)
{
	vector<ll> isP(n+1, true);

	for(int i=2; i*i<=n; i++)
	{
		if(isP[i])
		{
			for(int j= i * i; j<=n; j+= i)
				isP[j] = false;
		}
	}

	for(ll i = 2; i<=n; i++)
		if(isP[i])cout<<i<<" ";
}


vector<int> primeFactors(int n)
{
	int cp = n;
	vector<int> out;
	while(n % 2 == 0)
	{
		out.push_back(2);
		n/=2;
	}
	while(n % 3 == 0)
	{
		out.push_back(3);
		n/=3;
	}
	for(int i = 5; (i <= n) && (i*i <= cp); i+= 6)
	{
		while(n % i == 0)
		{
			out.push_back(i);
			n/=5;
		}
		while(n % (i+2) == 0)
		{
			out.push_back(i+2);
			n/= (i+2);
		}
	}
	if(out.empty())out.push_back(n);
	return out;
}

bool isPrime(int n)
{
	if((n % 2 == 0) || (n % 3 == 0)) return false;
	for(int i = 5; i*i <= n; i += 6)
	{
		if((n % i == 0) || n % (i+2) == 0)
			return false;
	}
	return true;
}

int MDC(int a, int b) // a0 = 15 e bo = 12
{
	int tmp;
	while(b != 0)
	{
		tmp = a; // 15, 12
		a = b; // 12, 3
		b = tmp % b; // 3, 0
	}
	return a;
}

int MMC(int a, int b)
{
	int mdc = MDC(a,b);
	int mmc = (a * b)/mdc;
	return mmc;
}

int factorial (int n)
{
	int fact = 1;
	for(int i = n; i > 1; i--)
		fact *= i;
	return fact;
}

int numb_digits(int &n)
{
	return (int)floor(log10(n) + 1);
}

bool is_palindrome(int n)
{
	int copy = n;
	int reversed = 0;
	int n_dig = numb_digits(n);
	if(n_dig == 1) return true;

	while(copy != 0)
	{
		reversed = reversed * 10 + (copy % 10);
		copy /=10;
	}
	return reversed == n;
}

void solve()
{
	cout<<power(2,10)<<endl;
	cout<<r_power(2,10)<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}

