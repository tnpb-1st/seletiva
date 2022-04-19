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
	int h1,a1,c1,h2,a2;
    cin >> h1 >> a1 >> c1 >> h2 >> a2;
    // int max_strikes = ceil((float)h2/a1);
    queue<string> ans;
    while(h2 > 0)
    {
        if((h1 <= a2) && (h2 > a1))
        {
            h1+=c1;
            ans.push("HEAL");
        }
        else
        {
            h2-=a1;
            ans.push("STRIKE");
            // max_strikes--;
        }
        h1-=a2;
    }
    cout<<ans.size()<<endl;
    while(ans.size())
    {
        cout<<ans.front()<<endl;
        ans.pop();
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