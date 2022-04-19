#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
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
    vector<string> words, patterns;
    string s;
    while(n--)
    {
        cin >> s;
        words.pb(s);
    }
    while(cin >> s)
    {
        patterns.pb(s);
    }
    for(auto &pattern:patterns)
    {
        queue<string> results;
        for(auto &c: pattern)
        {
            if(results.empty())
            {
                if(c == '#')
                {
                    for(int i = 0; i < 10; i++)
                        results.push(to_string(i));
                }
                else
                {
                    for(auto &w: words)
                        results.push(w);
                }
            }
            else
            {
                queue<string> tmp;
                while(!results.empty())
                {
                    string top = results.front();
                    results.pop();
                    if(c == '#')
                    {
                        for(int i = 0; i < 10; i++)
                            tmp.push(top + to_string(i));
                    }
                    else
                    {
                        for(auto &w:words)
                            tmp.push(top + w);
                    }
                }
                results = tmp;
            }
        }
        while(results.size())
        {
            cout << results.front()<<endl;
            results.pop();
        }
    }
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	solve();
	return 0;
}
