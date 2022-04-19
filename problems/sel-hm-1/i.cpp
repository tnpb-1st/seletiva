#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define INF (int)(2e9)
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
	ll t,x, min_val = INF;
	stack<ll> S;
    multiset<ll> se;
	string s, l;
	getline(cin,s);
	stringstream SS(s);
	SS >> t;
	while(t--)
	{
		getline(cin,s);
		stringstream SS(s);
		SS>>l;
		if(l == "PUSH")
		{
			SS >> x;
			min_val = min(x, min_val);
			S.push(x);
            se.emplace(x);
		}
		else if (l == "POP")
		{
			if(S.empty())
				cout<<"EMPTY"<<endl;
			else
            {
                x = S.top();
				S.pop();
                se.erase(se.find(x));
            }
		}
		else
		{
			if(S.empty())
				cout << "EMPTY"<<endl;
			else
				cout<<*se.begin()<<endl;
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