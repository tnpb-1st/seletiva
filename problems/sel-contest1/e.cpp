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
	int t;
	string s;
	cin >>t;
	while(t--)
	{
		cin >> s;
		if(s.size() & 1)
			cout << "NO"<<endl;
		else
		{
			bool a = true;
			for(int i = 0, j = s.size()/2; i < (int)s.size()/2; i++, j++)
			{
				// cout <<s[i]<<s[j];
				if(s[i]!=s[j])
				{
					a = false;
					break;
				}
			}
			if(a)
				cout << "YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
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