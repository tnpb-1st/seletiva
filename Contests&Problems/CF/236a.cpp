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
	string s;
	cin >> s;
	int A[123] = {};
	int num = 0;
	for(int c: s)
	{
		if(A[c] == 0)
		{
			A[c] = 1;
			num++;
		}
	}
	if(!(num & 1))
		cout << "CHAT WITH HER!"<<endl;
	else
		cout << "IGNORE HIM!"<<endl;

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