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
string s = "";

int TOH(int n, string A, string B, string C, int &n_m, string &res)
{
	if(n == 1)
	{
		n_m++;
		res += A + " " + C + '\n'; 
		return n_m;
	}
	n_m = TOH(n-1, A, C, B, n_m, res);
	res += A + " " + C + '\n';
	n_m++;
 	n_m = TOH(n-1, B, A, C, n_m, res);
	return n_m;
}


void solve()
{
	int n;
	cin >> n;
	int cont = 0;
	TOH(n,"1","2","3",cont, s);
	cout << cont << endl << s;
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