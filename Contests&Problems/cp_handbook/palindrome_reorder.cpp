#include <bits/stdc++.h>
#define endl '\n'
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
	string s, ev="", od="", res="";
	cin >> s;
	vector<int> A(1000,0);
	vector<bool> B(1000, false);
	int od_cont = 0;
	bool isPossible = true;
	for(char &c:s)
	{
		int x = c;
		A[x]++;
	}
	for(char &c:s)
	{
		int x = c;
		if(A[x] % 2 == 0 && B[x] == 0)
		{
			for(int i = 0; i < A[x]/2; i++)
				ev += c;
			B[x] = 1;
		}
		else if(A[x] % 2 != 0 && B[x] == 0)
		{
			od_cont++;
			if(od_cont > 1)
			{
				isPossible = 0;
				break;
			}
			B[x] = 1;
			for(int i = 0; i < A[x]; i++)
				od += c;
		}
	}
	if(isPossible)
	{
		res = ev + od;
		for(int i = ev.size() - 1; i > -1; i--)
			res += ev[i];
		cout << res;	
	} else
	{
		cout<<"NO SOLUTION";
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