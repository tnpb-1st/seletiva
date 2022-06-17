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
	int n;
	cin >> n;
	vll A(n);
	vll P(n);
	ll k;
	for(int i = 0; i < n; i++){
		cin >> k;
		A[i] = k;
	}
	P[0] = A[0];
	for(int i = 1; i < n; i++){
		P[i] = P[i-1] + A[i];
	}
	int l = n/2;
	ll smallest = P[n-1];
	ll v1, v2, diff;
	for(int i = l - 1; i < n; i++)
	{
		v1 = P[i];
		if(i - l >= 0)
		{ 
			v1 -= P[i - l];
		}
		v2 = P[n-1] - v1;
		diff = abs(v2 - v1);
		if(diff < smallest)
			smallest = diff;
	}
	cout << smallest;
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