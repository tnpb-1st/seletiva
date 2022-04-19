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
	string a, b;
	cin >> a >>b;
	queue<char> qa, qb;
	for(char &c:a) qa.push(c);
	for(char &c:b) qb.push(c);

	int num_moves = 0;
	while(!qa.empty() && !qb.empty())
	{
		// cout << qa.size() << " " << qb.size()<<endl;
		if(qa.size() == qb.size())
		{
			int n1 = 0, n2 = 0;
			if(qa.size() && qb.size() && (qa.front() == qb.front()))
			{
				while(qa.front() == qb.front() && qa.size() > 0)
				{
					n1++;
					n2++;
					qa.pop();
					qb.pop();
				}
				if(qa.size() > 0)
				{
					num_moves += n1 + n2;
				}
			}else
			{
				qa.pop();
				qb.pop();
				num_moves+=2;
			}
		}
		else if(qa.size() > qb.size())
		{
			num_moves++;
			qa.pop();
		}
		else if (qb.size() > qa.size())
		{
			num_moves++;
			qb.pop();
		}
	}

	cout << num_moves << endl;
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