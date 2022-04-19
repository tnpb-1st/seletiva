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
vector<string> get(int n)
{
	vector<string> actual;
	if(n == 1)
	{
		actual.pb("0");
		actual.pb("1");
		return actual;
	}
	vector<string> prev = get(n-1);
	for(int i = 0; i < (int)prev.size(); i++)
	{
		string s="";
		s+="0";
		s+=prev[i];
		actual.pb(s);
	}

	for(int i = (int)prev.size() - 1;  i >= 0; i--)
	{
		string s="";
		s+="1";
		s+=prev[i];
		actual.pb(s);
	}
	return actual;
}

void solve()
{
	int n;
	cin >> n;
	vector<string> ans = get(n);
	for(auto &s:ans)
	{
		cout << s << endl;
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