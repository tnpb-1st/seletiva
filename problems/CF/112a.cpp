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
int processStrings(string s1 ,string s2)
{
	int s_len = s1.size();
	for(int c1, c2, i = 0; i < s_len; i++)
	{
		c1 = s1[i];
		c2 = s2[i];
		if(c1 >= 97)c1 = c1 - 97 + 65;
		if(c2 >= 97)c2 = c2 - 97 + 65;
		if(c1 < c2) return -1;
		else if(c1 > c2) return 1;
		else
			continue;
	}
	return 0;
}

void solve()
{
	string s1, s2;
	int res;
	cin >> s1 >> s2;
	res = processStrings(s1,s2);
	cout << res << endl;
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